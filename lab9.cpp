import heapq
from collections import defaultdict, Counter

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
 
    freq = Counter(text)
    heap = [Node(char, freq) for char, freq in freq.items()]
    heapq.heapify(heap)
    
 
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(heap, merged)

    return heap[0]

def generate_codes(node, prefix="", code_map=None):
    if code_map is None:
        code_map = {}
    if node:
        if node.char:  
            code_map[node.char] = prefix
        generate_codes(node.left, prefix + "0", code_map)
        generate_codes(node.right, prefix + "1", code_map)
    return code_map

def huffman_encode(text, code_map):
    return ''.join(code_map[char] for char in text)

def huffman_decode(encoded_text, root):
    decoded_text = []
    current_node = root
    for bit in encoded_text:
        current_node = current_node.left if bit == "0" else current_node.right
        if current_node.char: 
            decoded_text.append(current_node.char)
            current_node = root
    return ''.join(decoded_text)

if __name__ == "__main__":
    text = "grigoryan"

    root = build_huffman_tree(text)

    code_map = generate_codes(root)
    print("Huffman Codes:", code_map)

    encoded_text = huffman_encode(text, code_map)
    print("Encoded Text:", encoded_text)

    decoded_text = huffman_decode(encoded_text, root)
    print("Decoded Text:", decoded_text)

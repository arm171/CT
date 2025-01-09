# LZ77 
def lz77_compress(data, window_size=20):
    compressed_data = [] 
    i = 0  # yntacik tarri  index
    while i < len(data):
        match_length = 0  #hamynknman erkarutyun
        match_distance = 0  # hamynknman heravorutyun
        
        #amenaerkar hamynknum
        for j in range(max(0, i - window_size), i):
            length = 0  
            while i + length < len(data) and data[j + length] == data[i + length]:
                length += 1
                if j + length >= i:
                    break
            if length > match_length:
                match_length = length
                match_distance = i - j
        if match_length > 0:
            next_char = data[i + match_length] if i + match_length < len(data) else ''
            compressed_data.append((match_distance, match_length, next_char))
            i += match_length + 1 
        else:
            compressed_data.append((0, 0, data[i]))
            i += 1
        
    return compressed_data 


def lz77_decompress(compressed_data):
    decompressed_data = [] 
    
    for entry in compressed_data:
        match_distance, match_length, next_char = entry
        if match_length > 0:
            start = len(decompressed_data) - match_distance 
            for i in range(match_length):
                decompressed_data.append(decompressed_data[start + i]) 
        decompressed_data.append(next_char)
        
    return ''.join(decompressed_data)  


data = "abcabcabcabc"  

compressed = lz77_compress(data)
print("Compressed Data:", compressed)
decompressed = lz77_decompress(compressed)
print("Decompressed Data:", decompressed)

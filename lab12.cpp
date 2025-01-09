import threading
import time

global_counter = 0  
quit_program = False 
lock = threading.Lock()


def my_async_thread():
    global global_counter, quit_program
    while not quit_program:
        with lock: 
            global_counter += 1
            if global_counter > 100:  
                quit_program = True
            print(f"MyAsyncThread: {global_counter}")
        time.sleep(0.1)  

def main():
    global global_counter, quit_program

    thread = threading.Thread(target=my_async_thread)
    thread.start()

    while not quit_program:
        with lock: 
            global_counter += 1
            if global_counter > 5000:  
                quit_program = True
            print(f"Main loop: {global_counter}")
        time.sleep(0.05) 


    thread.join()
    print("Program finished.")


if __name__ == "__main__":
    main()

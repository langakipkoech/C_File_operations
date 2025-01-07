# File Copy Utility with Real-Time Progress in C

## **Overview**

This C program is a simple and efficient file copy utility that demonstrates the use of low-level system calls (`open`, `read`, `write`, and `stat`) to copy a file from a source to a destination. While copying, the program dynamically calculates and displays the progress percentage in real time.

---

## **Features**
1. **Efficient File Copying**:
   - Reads and writes data in chunks using a buffer to optimize performance.
   - Supports copying of files of any size.

2. **Dynamic Progress Display**:
   - Calculates the progress percentage based on the total file size and bytes copied.
   - Dynamically updates the progress on the same line in the terminal.

3. **Error Handling**:
   - Handles errors gracefully for file operations like opening, reading, writing, and retrieving file metadata.

4. **Cross-Platform Compatibility**:
   - Designed for Unix-like systems (Linux, macOS) using POSIX-compliant system calls.

---

## **How It Works**

1. **Retrieve Source File Size**:
   - Uses `stat()` to get metadata about the source file, including its size (`st_size`), which is used for progress calculation.

2. **File Operations**:
   - Opens the source file for reading and creates/truncates the destination file for writing using `open()` with appropriate flags and permissions.

3. **Data Transfer**:
   - Reads data in chunks (determined by the buffer size) from the source file and writes it to the destination file using `read()` and `write()` system calls.

4. **Progress Calculation**:
   - Tracks the total bytes copied and calculates the percentage progress using the formula:
     ```
     progress = (copied_bytes * 100) / total_size;
     ```

5. **Dynamic Progress Update**:
   - Displays the progress percentage in the terminal dynamically, overwriting the previous value using the `\r` escape sequence.

---

## **Code Explanation**

### **Core Functions**
1. **`open()`**:
   - Opens the source file for reading (`O_RDONLY`).
   - Creates/truncates the destination file for writing (`O_CREAT | O_WRONLY | O_TRUNC`).

2. **`read()` and `write()`**:
   - Reads chunks of data from the source file into a buffer.
   - Writes the data from the buffer to the destination file.

3. **`stat()`**:
   - Retrieves metadata of the source file, including its size (`st_size`), for progress calculation.

4. **`close()`**:
   - Ensures proper closure of file descriptors after operations are completed.

5. **Dynamic Progress Display**:
   - Uses `\r` to overwrite the same line in the terminal, displaying the updated progress percentage.

---

## **Program Usage**


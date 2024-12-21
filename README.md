# Sorting Visualization
This project demonstrates visualizations of sorting algorithms using the SFML library in C++.

## Features
- Real-time visualization of the sorting process.
- Interactive graphical window.
- Supports customization of the number of elements and choice of sorting algorithm.

## Requirements
- **SFML 2.5** or later
- A C++ compiler supporting C++17 or later (e.g., g++ or MSVC)

## Setup Instructions
1. **Clone the repository**:

   ```bash
   git clone https://github.com/banovicc/sorting-visualization.git
   cd sorting-visualization
   ```

2. **Install SFML**:

   - On Ubuntu:
     ```bash
     sudo apt-get install libsfml-dev
     ```
   - On Windows:
     - Download the SFML library from [SFML Downloads](https://www.sfml-dev.org/download.php).
     - Follow the setup guide for your compiler.
   - On macOS:
     ```bash
     brew install sfml
     ```

3. **Compile the program**:

   ```bash
   g++ -o sorting_visualization main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. **Run the program**:
   ```bash
   ./sorting_visualization
   ```

## How to Use
1. **Choose the number of elements**:
   At the prompt, enter the number of elements to sort (e.g., `50`).

2. **Select a sorting method**:

   - Enter `1` for **Bubble Sort**.
   - Enter `2` for **Quick Sort**.

3. **View the visualization**:
   Watch as the rectangles are sorted in real-time. The height of each rectangle represents its value.

## Customization
- **Window Size**:
  The default window size is `1200x800`. You can adjust this in the `RenderWindow` initialization in the `main()` function.

- **Frame Rate**:
  The frame rate is capped at `60`. Modify `window.setFramerateLimit()` to change this.

## Example Output
After compiling and running, you'll see a graphical window displaying bars being sorted in real-time based on the selected algorithm.

## Contributing
Feel free to open issues or submit pull requests to improve this project.
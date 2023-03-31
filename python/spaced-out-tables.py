# Bad way!
data = [4.2, 7.9, 3452.3, 5.6]

header = 'Val1  Val2  Val3  Val4'

print(header)
for d in data:
    print(f'{d}   ', end='') # Simply print each data value with a fixed number of spaces.
print('\n\n')

# Better way!
header2 = ['Val1', 'Val2', 'V3', 'Val4'] # Define header as an array of column names.
data2 = [[4.2, 7.9, 124.3, 5.6],
         [1472.9, 5.3, None, -19.8]] # Define data as a 2d array, each array being a row. Any blank values are set to None.


def spaced_out_table(header, data, min_spaces):
    """Prints out a perfectly spaced out table. Each column is dynamically sized based on its largest value.

    Args:
        header (1D array of strings): Represents the column names of the table.
        data (2D array of anything that can be casted as a string usint str()): Represents the rows of data. Use 'None' in the array for blank values.
        min_spaces (int): The number of spaces in between the columns.
    """
    num_cols = len(header) # Get the number of columns.
    
    # Find the minimum spaces in between each piece.
    spaces = [len(h) + min_spaces for h in header]
    
    # Update based on max length of data.
    temp = 0
    for col in range(len(header)):
        for row in range(len(data)):
            if len(str(data[row][col])) > temp:
                temp = len(str(data[row][col])) # Update if the length of that value is greater than the temp variable.
                
        if temp >= (spaces[col] - min_spaces):
            spaces[col] = temp + min_spaces; # Update the length if the temp length is greater.
    
    # Write header.
    for i in range(len(header)):
        print(header[i], end='')
        for _ in range(len(str(header[i])), spaces[i]):
            print(' ', end='') # Print trailing spaces.
    
    print() # Print line break.
    
    # Write data.
    for d in data:
        for i in range(num_cols):
            print(d[i] if d[i] != None else '    ', end='') # Print the data, or just empty if there is nothing to print.
            for _ in range(len(str(d[i])), spaces[i]):
                print(' ', end='') # Print trailing spaces.
        print() # Print line break.
    

spaced_out_table(header2, data2, 2) # Sample.
# ZOHO_Task
Task1.cpp :
In a folder, have some files in .txt format. Read the contents of the file and remove the words if they are printed more than once. 
Example: "Read a file file file" has to be converted to "Read a file".
Create 10 threads and do the above processing in a parallel manner.
If the number of files is less than 10, then create number of threads equal to the number of files. 
Example: If there is only one file in the folder then create only one thread.
Print the total time taken for execution.

Task2.py :
In a folder, have some files in .txt format. Read the contents of the file and remove the words if they are printed more than once. 
Example: "Read a file file file" has to be converted to "Read a file".
Create 10 threads and do the above processing in a parallel manner.
If the number of files is less than 10, then create number of threads equal to the number of files. 
Example: If there is only one file in the folder then create only one thread.
Print the total time taken for execution.

Task3.ipynb :
Choose any machine learning model with unstructured data, train the model and predict for test input.

Task4.ipynb :
Train a model with unstructured data with a minimum of 100 epochs and prove that increasing epoch decreases the loss.

Task5.ipynb :
Train the same model with one hidden layer.Document the performance improvement on using this layer.

Task6(cpu).ipynb & Task6(gpu).ipynb :
Compare the training times on a CPU vs GPU.

Task7.cpp & Task7.ipynb :
Create python library which will get audio as input using pytorch.
Apply the following augmentation techniques: Reverberation, Reduce the speed by 0.5.
Now write a cpp program to get the audio input and store it as array.
Use python bindings, to read the array of audio return from cpp program and apply augmentation technique listed above and create a new audio file with the augmentation changes.
Calculate the torchmetrics PESQ and STOI on the audio files with and without the augmentation changes.

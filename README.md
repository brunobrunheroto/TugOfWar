# Tug Of War
<p>Tug of war is a project done in C language that demonstrates the dispute between different threads for the position of a flag in an array filled with underscore characters "_".</p>

## <ins>Goals</ins>
<p>This project was done for academic purposes and aims to demonstrate how threads work and how they behave during runtime.</p>

## <ins>How it works</ins>
<p>Initially, an array of 88 positions is created and filled with underscore characters "_". The flag, formed by three characters "ABC", is then placed exactly in the middle of the array, at positions 42, 43 and 44. The last position of the array will always be a character "\0" (string terminator).</p>
<p>Once this is done, the initial array should look like this:</p>
<p>__________________________________________ABC__________________________________________\0</p>
<p>The initial flag position, 42, is stored in a variable x, and is used to modify the flag's position at runtime.</p>
<p>The threads that will compete are called "tothestart" and "totheend". "tothestart" subtracts 1 from x and "totheend" adds 1 from x. Both modify the flag's position using the x position, bringing it closer to the start or end respectively and sleep for a period "t", calculated through the function:</p>
<p>t = (long) (drand48() * 202010101/89.0);</p> 
<p>The program then draws quantities q1 and q2 of threads, obeying 7 <= (q1,q2) <= 22 and creates them. q1 will be the number of "tothestart" threads and q2 the number of "totheend" threads.</p>
<p>The threads are created alternately, so that none has an advantage over the other on the competition.</p>
<p>After the threads are created, the main thread will continue to run concurrently with them an execution loop with the following commands:</p>

- Clear the screen: system("clear");
- Print q1 and q2: printf("tothestart: %d\ttotheend: %d\n", q1, q2);
- Print the array:  printf("%s\n", a);
- Test the character position (x) of your name. If it reaches the beginning (0), or the end (86-2), it will display a message pointing to the winning thread team (totheend or tothestart) and then end the game.

<p>At each execution, the main thread sleeps for an adjusted period of time so as not to overload the processing.</p>

## <ins>How to use </ins>
- Download the TugOfWar.c file on this repository.
- Install codeblocks.
- On Settings -> Compiler -> Linker Settings, add "-pthread" to the "Other Linker options" field.
- Click "Compile and Run" or "Compile" and "Run" respectively.

## <ins>Execution of the program:</ins>
![TugOfWar](https://user-images.githubusercontent.com/67275098/175830228-f6e61e7c-8497-4ad0-854f-f47b90b85fd5.gif)

## <ins>Credits</ins>
<p> The ideia to work on this project and it's structure was shared by the teacher of Operating Systems at Facamp, José Martins Junior.</p>

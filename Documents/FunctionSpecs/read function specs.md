## Read Function Specs

```c
void read()
{
  //Takes user input from input buffer
  //Places variables into weight, box-size, and destination
  //Sends variables to validate() function
}
```

Since the return value is void, and this function requires 0 parameters, a unit test won't be required for this function. The purpose of this function is to extract the user input from the input stream, and send the user input to the validate() function. Thus, testing the validate function will verify that this function works as intended.

## Validate Function Specs

The purpose of this function is to receive user-input from the the read() function, and validate that the shipment parameters are valid.

```c++
int validate(double size, int weight, struct Point destination)
{
  //Validates each variable
  //Sends correct error message
  //Returns appropriate int value 
}
```

###### The Return value is:
> 1 if valid
> 
> -1 if invalid size
> 
> -2 if invalid weight
> 
> -3 if invalid destination
> 
> 0 if invalid

**double size:** size of shipment (0.25, 0.50, or 1.00) cubic meter

**int weight:** weight of shipment in kg (must be 1-1000kg)

**struct Point destination:** Must be between {0,0} to {25,25}

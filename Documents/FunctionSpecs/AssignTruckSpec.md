# `AssignTruck` Function Specs

## Purpose 
Calculate which truck is best to deliver the shipment `s`, and assign the shorestest route to the respective truck

## Parameters
- `struct Shipment s`: shipment to ship, contains the destination coordinates
- `struct Truck trucks[3]`: list of available trucks 
- `const struct Map *map`: map of city that the trucks route travels through

## Return Value(s)
- `int bestTruck`: returns a non-zero number indicating which truck the shipment was assigned to based on the trucks color code
  - Example: if a shipment went on the "Blue Truck", the function returns `2`
### Possible Return Values
  - `2`: shipment is assigned to the blue truck
  - `4`: shipment is assigned to the green truck
  - `8`: shipment is assigned to the yellow truck
  - `-1`: shipment cannot be delivered 


```c
int AssignTruck(struct Shipment s, struct Truck trucks[3], const struct Map *map)
{
  // bestTruck - return variable, returns which truck the shipment will go in  

  // maxRouteLen - varible to store the longest truck route

  // Loop - find which truck has the longest route, store in "maxRouteLen"

  // Loop - find which truck is best at each step of each step of each truck
  
  //      - compares trucks current distance to destination
  //      - compars trucks available weight and volume 
  //      - assigns the best route to respective truck


  // returns bestTruck -  best truck via corresponding color code
}
```


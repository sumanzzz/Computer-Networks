INF=999

def input_topology():

  n=int(input("Enter the number of routers: "))

  routers=[chr(65+i) for i in range(n)]

  print("\nEnter the cost matrix (use 999 for infinity):")

  cost=[]

  for i in range(n):

   row=list(map(int, input(f"Row {i+1}: ").split()))

   cost.append(row)

  return n,routers,cost

 

def distance_vector_routing(n,routers,cost):

   dist=[[cost[i][j] for j in range(n)] for i in range(n)]

   next_hop=[[j for j in range(n)] for i in range(n)]

   print("\nInitial distance tables:")

   print_tables(routers,dist,next_hop)

   

   updated=True

   iteration=0

   while updated:

     updated=False

     iteration +=1

     print(f"\n===Iteration {iteration}===")

     for i in range(n):

        for j in range(n):

          for k in range(n):

            if dist[i][j]>cost[i][k]+dist[k][j]:

                dist[i][j]=cost[i][k]+dist[k][j]

                next_hop[i][j]=k

                updated=True

     print_tables(routers,dist,next_hop)

   print("\nConverged after",iteration,"iteration(s).")

   return dist,next_hop

   

def print_tables(routers,dist,next_hop):

  n=len(routers)

  for i in range(n):

    print(f"\nRouter {routers[i]} Routing Table:")

    print("Destination | Cost | Next Hop")

    for j in range(n):

      cost_str="INF" if dist[i][j]>= INF else str(dist[i][j])

      nh=routers[next_hop[i][j]]

      print(f" {routers[j]} | {cost_str:>3} | {nh}")

    print("-"*30)

def main():

  n,routers,cost=input_topology()

  distance_vector_routing(n,routers,cost)

if __name__=="__main__":

  main()
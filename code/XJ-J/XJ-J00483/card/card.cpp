#include<bits\stdc++.h>
using namespace std;



int main(){
	    	        freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
   int m = 0;
   int n = 0;
   cin>>n>>m;

int tim[100000];
for(int i(0);i<100000;i++){
	tim[i] = 0;
}
   	int u;
   for(int i(0);i<n;i++){

   	cin>>u;

   		tim[u]++;
   	}
   
   for(int j(1);j<=m;j++){
   		cout<<tim[j]*n<<" ";
   	}
}
    
    
    
    




#include<iostream>
using namespace std;
int main(){
   int n,a,e;
   string b,c;
   cin>>n;
   for(int i=1;i<n;i++){
      cin>>a;
      cin>>b[i-1];
      c+=b[i];
      }
      for(int i=1;i<=n;i++){
         if(c[i-1]==c[i]){
             e+=1;
         }
      }
      if(e==n){
         cout<<0;
      }
	return 0;
}


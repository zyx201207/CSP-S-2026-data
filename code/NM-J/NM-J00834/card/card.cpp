#include <iostream>
using namespace std;
int main(){
      freopen("card.in","r",stdin);
      freopen("card.out","w",stdout);
      long long a,b,c,d;
      cin>>a>>b>>c>>d;
      if(a == 0){
		  cout<<0;
		  return 0 ;
	  }
	  else{
          long long sum = (a*b)+(c*b);
          cout<<sum;
          return 0 ;
	  }
      return 0;
} 

#include <iostream>
using namespace std;
int main(){
      freopen("travel.in","r",stdin);
      freopen("travel.out","w",stdout);
      long long sum = 0;
      long long n;
      cin>>n;
      if(n == 0){
		  cout<<0;
	  }
	  else{
          for(int i =  1 ; i<n; i++){
		      long long a,b,c;
		      cin>>a>>b>>c;
		      sum += a;
		      sum += b;
		      sum += c;
	  }
	  cout<<sum;
      return 0;
}
} 

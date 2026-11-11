#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=3*1e5+10;;
int a[N],t[M];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h=max(h,a[i]);
		t[a[i]]++;
	}
    int j=1;
  for(int i=1;i<=h;i++){
  	if(t[i]>1){
  		j=0;
	  }
  }
  if(j=1){
  	for(int i=1;i<=h;i++){
  		if(t[i]!=0){
  			cout<<n<<" ";
		  }else{
		  	cout<<"0"<<" ";
		  }
	  }
  }else{
  	cout<<"1";
  }
	return 0;
} 

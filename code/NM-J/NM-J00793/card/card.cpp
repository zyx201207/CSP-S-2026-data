#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,n,w;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>n;
			if(n==n+1)w+1;cout<<w;break;
		}
	}
return 0;
	}
	


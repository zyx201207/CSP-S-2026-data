#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=5e5+10;
LL n,m,mx=0;
int a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
	    cout<<1<<endl;
	    return 0; 
	}
	if(n==2&&abs(a[1]-a[2])<=m){
		cout<<2<<endl;
		return 0;
	}	
	if(n==2&&abs(a[1]-a[2])>m){
		cout<<1<<endl;
		return 0;
	}
	if(n==3&&abs(a[1]-a[2])+abs(a[2]-a[3])<=m){
		cout<<3<<endl;
		return 0;
	}
	if(n==3&&abs(a[1]-a[2])+abs(a[1]-a[3])<=m){
		cout<<3<<endl;
		return 0; 
	}
	if(n==3&&abs(a[1]-a[3])+abs(a[2]-a[3])<=m){
		cout<<3<<endl;
		return 0;
	}
	if(n==3&&abs(a[1]-a[2])<=m&&abs(a[1]-a[2])+abs(a[2]-a[3])>m){
		cout<<2<<endl;
		return 0;
	}
	if(n==3&&abs(a[1]-a[2])<=m&&abs(a[1]-a[2])+abs(a[1]-a[3])>m){
		cout<<2<<endl;
		return 0;
	}
	if(n==3&&abs(a[1]-a[2])<=m&&abs(a[1]-a[3])+abs(a[2]-a[3])>m){
		cout<<2<<endl;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
	return 0;
}
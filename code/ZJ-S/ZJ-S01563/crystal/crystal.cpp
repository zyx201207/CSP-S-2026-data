#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m,z;
int a[N];
int def(int x,int y){
	//cout<<y<<" ";
	if(a[x]+y/x>=a[x+1] && y-(a[x+1]-a[x])*x>=0)def(x+1,y-(a[x+1]-a[x])*x);
	else{
		//cout<<x<<" ";
		int t=x;
		if(a[x]+y-a[x+1]==0){
			//cout<<y;
			t+=1;
		}
		z=t;
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag1=1,flag2=1;//a,b
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1])flag1=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag2=0;
	}
	if(flag1==1){
		cout<<n;
	}
	sort(a+1,a+n+1);
	if(m<a[2]-a[1])cout<<1;
	def(1,m);
	cout<<z;
}

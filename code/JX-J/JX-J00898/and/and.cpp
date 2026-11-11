#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxk,cnt;
void f(int x,int y,int z,bool s){
	if(x==n||y==-1)return;
	if(s==1){
		if(y==m-1)z=a[x];
		else z=(a[x]&z);
	}
	if(y==0){
		maxk=max(z,maxk);
		return;
	}
	f(x+1,y,z,0);
	f(x+1,y-1,z,1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	f(0,m,0,0);
	f(0,m-1,0,1);
	cout<<maxk;
	return 0;
}

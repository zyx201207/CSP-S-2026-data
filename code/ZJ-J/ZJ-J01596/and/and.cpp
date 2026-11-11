#include<bits/stdc++.h>
using namespace std;
int n,m,a[200008],ma=-1,vis[200008];
void f(int x,int y){
	if(x==m+1){
		ma=max(ma,y);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			f(x+1,y&a[i]);
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f(1,int(pow(2,30)-1));
	cout<<ma;
	return 0;
} 

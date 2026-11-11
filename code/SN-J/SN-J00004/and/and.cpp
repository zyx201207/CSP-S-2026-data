#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],Ma=0;
void xh(int x,int y,int u){
	if(x==m)Ma=max(u,Ma);
	for(int i=y;i<=n;i++){
		xh(x+1,i+1,u&a[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Ma=max(Ma,a[i]);
    }
	if(m==1){
		cout<<Ma;
	}
	if(m==2){
		Ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				Ma=max(Ma,a[i]&a[j]);
			}
		}
		cout<<Ma;
	}
	else if(m==n)
	{
		Ma=a[1];
		for(int i=2;i<=n;i++){
			Ma&=a[i];
		}
		cout<<Ma;
	}
	else
	{
		Ma=0;
		for(int i=1;i<=n;i++){
			xh(0,i,a[i]);
		}
		cout<<Ma;
	}
	return 0;
}

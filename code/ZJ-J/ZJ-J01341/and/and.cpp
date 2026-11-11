#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[2005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				mx=max(mx,a[i]&a[j]);
		cout<<mx;
	}else if(m==n){
		int mx=a[1];
		for(int i=2;i<=n;i++)
			mx=mx&a[i];
		cout<<mx;
	}
	return 0;
}
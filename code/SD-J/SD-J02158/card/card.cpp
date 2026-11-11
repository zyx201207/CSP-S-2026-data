#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<n-i+1<<" ";
		}
	}
}

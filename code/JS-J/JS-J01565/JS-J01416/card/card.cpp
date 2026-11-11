#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int b[500007];
int last[300001];
int ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		b[i]=1;
	}
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=b[i];
		b[last[a[i]]+1]+=b[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

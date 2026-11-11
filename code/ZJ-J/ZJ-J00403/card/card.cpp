#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],dp[300010];
struct P{
	int cnt,last;
}b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].cnt++;
		b[a[i]].last=i;
	}
	for(int i=1;i<=n;i++){
		int mx=i;
		for(int j=i;j<=n;j++){
			if(b[a[j]].cnt>1)mx=max(mx,b[a[j]].last);
		}
		for(int j=mx;j<=n;j++){
			dp[a[j]]++;
		}
		b[a[i]].cnt--;
		if(i==b[a[i]].last)b[a[i]].last=0; 
	}
	for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],l[M][2],dp[M];
bool f1[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f1[a[i]]) l[a[i]][1]=i;
		else l[a[i]][0]=i;
		f1[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			dp[a[j]]++;
			if(l[a[j]][1]) j=l[a[j]][1]+1;
			else j++;
		}
	}
	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
	return 0;
} 

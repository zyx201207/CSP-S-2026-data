#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int maxm=300005;
int n,m;
int a[maxn];
int pos[maxm];
int ans[maxn];
int Ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(pos[a[i]]){
			for(int j=i+1;j<=pos[a[i]];j++)ans[j]=max(ans[j],i);
		}
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		Ans[a[i]]+=i-ans[i];
	}
	for(int i=1;i<=m;i++)cout<<Ans[i]<<" ";
	return 0;
}
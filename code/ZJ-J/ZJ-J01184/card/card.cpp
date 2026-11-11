#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ishave[M];
int ans[M];
int n,m;
int get(int x){
	for(int i=n;i>=1;i--)if(a[i]==x)return i;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)ishave[j]=0;
		int st=get(a[i]);
		for(int j=st;j<=n;j++){
			if(ishave[a[j]]){
				for(int pos=ishave[a[j]];pos<=n;pos++)ishave[a[pos]]=0;
			}
			ishave[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(ishave[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
code by Ace
*/


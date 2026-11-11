#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,f,cnt;
int a[500010];
int t[500010];
int l[300010];
int ans[300010];
int pre[300010];
void solve1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n])//first,last
			ans[a[i]]++,ans[a[n]]++;
		else  ans[a[n]]++;
	}
	cout<<ans[1]<<' '<<ans[2];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[a[i]]++;
	}
	if(m==2){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		pre[a[i-1]]--;
		for(int j=1;j<=m;j++)
			l[j]=inf,t[j]=pre[j];
		for(int j=i;j<=n;j++){
			if(l[a[j]]==inf)  l[a[j]]=j;
			else{
				for(int k=l[a[j]];k<j;k++)
					t[a[k]]--,l[a[k]]=inf;
				l[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		if(t[j]>0)
			ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

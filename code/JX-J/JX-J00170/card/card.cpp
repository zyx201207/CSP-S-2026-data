#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
int f[500005];
int fin[300005];
struct fl{
	int zl,zb;
}nw[300005];
bool cmp(fl a,fl b){
	return a.zb>b.zb;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(fin[a[i]]==0)fin[a[i]]=i;
		f[fin[a[i]]]++;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		nw[i].zb=fin[i];
		nw[i].zl=i;
	}
	sort(nw+1,nw+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(nw[i].zb==n)break;
		else {
			f[fin[a[nw[i].zb+1]]]+=f[fin[a[nw[i].zb]]];
			cnt[a[nw[i].zb]]+=f[fin[a[nw[i].zb]]];
		}
	}
	for(int i=1;i<=m;i++){
		if(a[n]==i)cout<<n;
		else cout<<cnt[i]/2;
		cout<<' ';
	}
	return 0;
}


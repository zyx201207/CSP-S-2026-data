#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int n,m,a[MAXN];
int qzh[MAXN];
int ans[MAXN];
int val[MAXN],num[MAXN];
int id;
int fnans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]*i-qzh[i]<=m) ans[i]=ans[i-1]+1,fnans=max(fnans,ans[i]);
		else{
			id=i;
			break;
		}
	}
	int l=1;
	val[id-1]=qzh[id-1];
	for(int i=id;i<=n;i++){
		val[i]=val[i-1]+a[i];
		ans[i]=ans[i-1]+1;
		while(a[i]*(i-l+1)-(qzh[i]-qzh[l-1])>m){
			ans[i]--,val[i]-=a[l];
			l++;
		}
		fnans=max(fnans,ans[i]);
	}
	cout<<fnans;
	return 0;
}

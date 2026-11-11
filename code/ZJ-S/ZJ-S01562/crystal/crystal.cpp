#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],n,m;
struct node{
	int l,r;
	int val;
}f[50000010];
bool check(int nn){
	for(int i=2;i<=nn;i++){
		if(a[i]-a[i-1]!=1)return 0;
	}
	return 1;
}
bool pf(int nn){
	int k=a[2]-a[1];
	for(int i=2;i<=nn;i++){
		if(a[i]-a[i-1]!=k)return 0;
	}
	return 1;
}
bool cmp(node aa,node bb){
	return aa.val>bb.val;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check(n)){
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>m)break;
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	if(pf(n)){
		int kk=a[2]-a[1];
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			sum+=i*kk;
			if(sum>m)break;
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt++;
			f[cnt].l=i;
			f[cnt].r=j;
			int flag=0;
			for(int k=i;k<=j;k++){
				flag+=a[j]-a[k];
			}
			f[cnt].val=flag;
			if(f[cnt].val>m)break;
		}
	}
	sort(f+1,f+1+cnt,cmp);
	int ma=0;
	for(int i=1;i<=cnt;i++){
	//	cout<<f[i].val<<" "<<f[i].l<<" "<<f[i].r<<"\n";
		int l=f[i].r-f[i].l+1;
		if(f[i].val>m)continue;
		ma=max(ma,l);
	}
	cout<<ma;
	return 0;
}
/*
5 5 
1 2 5 8 9
*/

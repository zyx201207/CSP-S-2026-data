#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int u;
	char c;
}a[210000];
int kt[210000];
map<pair<int,int>,int>pre;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].c;
		l+=a[i].u;
		kt[i]=kt[i-1]+a[i].u;
	}
	int re=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			pre[{re+a[i].u,j}]=pre[{re,j}];
		}
		pre[{re+a[i].u,a[i].c-'a'}]+=a[i].u;
		re+=a[i].u;
	}
	int ks=1,ans=0;
	for(int i=1;i<=n;i++){
		if(ks>l/2)break;
		if(ks+a[i].u-1>l/2){
//			cout<<"!!!!"<<endl;
			int ll=(l+1)/2+1,r=l-ks+1;
			int t1=upper_bound(kt+1,kt+n+1,r)-kt-1;
			int t2=lower_bound(kt+1,kt+n+1,ll)-kt;
			int p=pre[{kt[t1],a[i].c-'a'}]-pre[{kt[t2],a[i].c-'a'}];
			p+=(r-kt[t1])*(a[t1+1].c==a[i].c)+(kt[t2]-ll+1)*(a[t2].c==a[i].c);
			ans+=(l/2-ks+1-p);
			break;
		} 
		int r=l-ks+1,ll=l-(ks+a[i].u-1)+1;
		int t1=upper_bound(kt+1,kt+n+1,r)-kt-1;
		int t2=lower_bound(kt+1,kt+n+1,ll)-kt;
//		cout<<ll<<' '<<r<<' '<<t2<<' '<<t1<<endl; 
		int p=pre[{kt[t1],a[i].c-'a'}]-pre[{kt[t2],a[i].c-'a'}];
		p+=(r-kt[t1])*(a[t1+1].c==a[i].c)+(kt[t2]-ll+1)*(a[t2].c==a[i].c);
		ans+=(a[i].u-p);
		ks+=a[i].u;
	}
	cout<<ans<<endl;
	return 0;
} 

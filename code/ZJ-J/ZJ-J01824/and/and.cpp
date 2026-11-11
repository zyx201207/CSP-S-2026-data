#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,f;
int maxi=-1;
int cnt[35];
struct node{
	int v,cnta;
}a[N];
int ksm(int p,int q){
	int res=1;
	while(q){
		if(q&1) res=res*p;
		p=p*p;
		q=q>>1;
	}
	return res;
}
bool cmp(node x,node y){
	return x.v>y.v;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		for(int j=1;j<=31;j++){
			if(a[i].v<ksm(2,j)){
				cnt[j]++;
				a[i].cnta=j;
				break;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i].v<<" "<<a[i].cnta;
//		cout<<"\n";
//	}
	for(int i=1;i<=31;i++){
		if(cnt[i]>=m){
			f=1;
			maxi=max(maxi,i);
		}
	}
//	cout<<maxi;
// ----------------------------------
	if(f==1){
		int cntppp=1;
		for(int i=1;i<=31;i++){
			if(cnt[i]<m&&i>maxi){
				cntppp+=cnt[i];
			}
		}
	//	cout<<cntppp;
		int ans=a[cntppp].v;
		for(int i=cntppp+1;i<=cntppp+m-1;i++){
			ans=ans&a[i].v;
		}
		cout<<ans;
		return 0;
	}
	int ans=a[1].v;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].v;
	}
	cout<<ans;	
	
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans[200005];
bool cmp(ll x,ll y){
	return x>y;
}
struct node{
	ll id,k[31];
}s[200005];
void fj(int x,int y){
	ll cnt=31;
	while(x>0){
		if(x-(1<<cnt)>=0){
			s[y].k[cnt]=1;
			x-=(1<<cnt);
		}
		cnt--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	ll maxx=0,maxx1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
			maxx1=i;
		}
	}
	for(int i=1;i<=n;i++){
		s[i].id=i;
		fj(a[i],i);
	}
	int tot=0;
	for(int i=0;i<31;i++){
		if(s[maxx1].k[i]==1){
			tot=i;
		}
	}
	int sum1=0,cnt1=0;
	for(int i=tot;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(s[j].k[i]==1){
				ans[++cnt]=a[j];
			}
		}
		if(cnt==m){
			cnt1=cnt;
			break;
		}else if(cnt>m){
			cnt1=m;
			break;
		}
	}
	int ans1=ans[1];
	for(int i=2;i<=cnt1;i++){
		ans1=ans1&ans[i];
	}
	cout<<ans1;
	return 0;
}

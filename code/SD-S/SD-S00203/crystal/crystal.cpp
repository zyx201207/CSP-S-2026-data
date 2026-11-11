#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct f{
	int num,cnt;
}a[500005];
ll n,m,k;
ll ans;
bool cmp(f x,f y){
	return x.num<y.num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		if(i==1){
			a[++k].num=x;
			a[k].cnt=1;
			continue;
		}
		if(x==a[k].num){
			a[k].cnt++;
		}
		else{
			a[++k].num=x;
			a[k].cnt=1;
		}
	}
	sort(a+1,a+k+1,cmp);
	if(k==1){
		cout<<n;
		return 0;
	}
	for(int i=k;i>=1;i--){
		ll sum=0,cnt=a[i].cnt;
		for(int j=i-1;j>=1;j--){
			ll gp=a[i].num-a[j].num;
			if(gp>(m-sum)){
				break;
			}
			else{
				if(gp*(a[i].cnt)+sum>m){
					sum=m-(m-sum)%gp;
					cnt+=(m-sum)/gp;
				} 
				else{
					sum+=gp*(a[i].cnt);
					cnt+=a[j].cnt;
				}
			} 
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

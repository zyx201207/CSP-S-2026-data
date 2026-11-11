#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,ans,l,r,sum,summ,k[N],cnt;
char s[N];
struct node{
	char c;
	ll len;
}a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>k[i]>>s[i];
		sum+=k[i];
	}
	bool flag=1;
	for(ll i=1;i<=n;i++){
		summ+=k[i];
		if(summ>sum/2&&flag){
			flag=0;
			if(s[i]==a[cnt].c){
				a[cnt++].len+=k[i]-(summ-sum/2);
				a[cnt].len=summ-sum/2;
				a[cnt].c=s[i];
			}else{
				a[++cnt].len=k[i]-(summ-sum/2);
				a[cnt].c=s[i];
				a[++cnt].len=summ-sum/2;
				a[cnt].c=s[i];
			}
		}else{
			if(s[i]==a[cnt].c){
				a[cnt].len+=k[i];
			}else{
				a[++cnt].len=k[i];
				a[cnt].c=s[i];
			}
		}
	}
//	cout<<cnt<<'\n';
//	for(ll i=1;i<=cnt;i++){
//		cout<<a[i].len<<' '<<a[i].c<<'\n';
//	}
	l=1;
	r=cnt;
	sum=0;
	while(l<r){
		sum+=a[r].len;
//		cout<<sum<<' '<<l<<' '<<r<<'\n';
		if(a[l].c==a[r].c){
			ans-=a[r].len;
			if(sum>=a[l].len){
				ans+=sum-a[l].len;
			}
		}
		if(sum>=a[l].len){
			ans+=a[l].len;
//			cout<<sum-a[l].len<<'\n';
			a[r].len=sum-a[l].len;
			l++;
			if(a[r].len==0){
				r--;
			}
			sum=0;
		}else{
			r--;
		}
	}
	cout<<ans;
	return 0;
}

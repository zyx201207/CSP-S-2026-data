#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;
int n;
ll m,cnt;
ll a[N],re[N];
ll pos;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pos=(n+1)/2;
	for(int i=1;i<=n;i++){
		re[i]=abs(a[i]-a[pos]);
	}
	ll l=pos-1,r=pos+1;
	while(m>0){
		ll sum=min(re[l],re[r]);
		if(m<sum){
			break;
		}
		m-=sum;
		cnt++;
		if(sum==re[l]){
			l--;
		}else{
			r++;
		}
	}
	cout<<cnt+1<<endl;
	return 0;
}

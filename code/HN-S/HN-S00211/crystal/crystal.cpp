#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+10;
ll a[N];
ll n,m;
ll num;
ll check(ll mid){
	ll sum=0;
	ll idx=m;
	for(int i=mid;i>=1;i--){
		if(abs(a[mid]-a[i])>=m){
			break;
			
		} 
		idx-=(a[mid]-a[i]);
		sum++;
	}
	if(sum>=num){
		num=sum;
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])){
				flag=false;
			}
		}
	}
	if(flag==true){
		if(a[1]>a[2]){
			int st,la;
			if(n%2==0){
				st=n/2;
				la=n/2+1;
			}
			else{
				st=n/2;
				la=n/2+2;
			}
			
			for(int i=1,j=n;i<=st,j>=la;i++,j--){
				swap(a[i],a[j]);
			}
		}
		for(int i=1;i<=n;i++){
			int idx=(a[1]+a[i])*i/2;
			idx-=i;
			if(idx>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	else{
		sort(a+1,a+1+n);
		ll l=0,r=n+1;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		cout<<num;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
    	cin >> a[i];
	}
	ll ma=1;
	if(m<=100000005){
		sort(a,a+n);
		//ll l=a[0],r=a[n-1];
		
//		while(l<=r){
//			ll mid=(l+r)/2;
//			ll sum=0;
//			ll st=upper_bound(a,a+n,mid)-a;
//			ll cost=m;
//			cout << mid << endl;
//			cout << st << endl;
//			for(int i=st-1;i>=0;i--){
//				if(mid-a[i]>cost)break;
//				else{
//					sum++;
//					cost-=(mid-a[i]);
//				}
//			}
//			cout << sum << '\n';
//			if(sum>=ma){
//				ma=sum;
//				l=mid+1;
//			}else{
//				r=mid-1;
//			}
//		}
		for(int i=a[0];i<=a[n-1];i++){
			ll sum=0;
			ll st=lower_bound(a,a+n,i)-a;
			ll cost=m;
			if(a[st]>i)st--;
			if(a[st]==a[st+1]){
				while(a[st]==a[st+1])st++;
			}
			//cout << i << endl;
			//cout << "st" << st << endl;
			for(int j=st;j>=0;j--){
				if(i-a[j]>cost)break;
				else{
					//cout << "j" << j << endl;
					sum++;
					cost-=(i-a[j]);
					//cout << "cost" << cost << endl;
				}
			}
			//cout << "sum" << sum << endl;
			ma=max(ma,sum);
		}
		cout << ma << endl;
	}else{
		sort(a,a+n);
		ll sum=0;
		for(int i=n-1;i>=0;i--){
			if(a[n-1]-a[i]>m)break;
			else{
				sum++;
				m-=a[n-1]-a[i];
			}
		}
		if(sum==0)sum=1;
		cout << sum << endl;
	}
	return 0;
}


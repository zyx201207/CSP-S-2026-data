#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m,ans,ans1,cnt,cnt1,mid,mid1,last;
ll a[N],t[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool opA=1,opB=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			last=a[i-1]-a[i-2];
		}
		cin>>a[i];
		t[a[i]]+=1;
		if(a[i]!=i){
			opA=0;
		}
		if(a[i]-a[i-1]!=last&&i>=3){
			opB=0;
		}
	}
	sort(a+1,a+1+n);
	if(opA){
		ll cnt=0;
		while(1){
			if(m>=cnt){
				m-=cnt;
			}
			else{
				break;
			}
			ans+=1;
			cnt+=1;
		}
	}
	else if(opB){
		int cnt=0;
		ll gc=a[2]-a[1];
		while(1){
			if(m>=cnt){
				m-=cnt;
			}
			else{
				break;
			}
			ans+=1;
			cnt+=gc;
		}
	}
	else{
		cnt=m,cnt1=m;
		if(n&1){
			mid=a[(n+1)/2];
			for(int i=(n+1)/2;i>=1;i--){
				cnt-=(mid-a[i]);
				if(cnt>0){
					ans+=1;
				}
			}
		}
		else{
			mid=a[n/2];
			mid1=a[n/2+1];
			for(int i=n/2;i>=1;i--){
				cnt-=(mid-a[i]);
				if(cnt>0){
					ans+=1;
				}
			}
			for(int i=n/2+1;i>=1;i--){
				cnt1-=(mid1-a[i]);
				if(cnt1>0){
					ans1+=1;
				}
			}
		}
	}
	if(opA||opB){
		cout<<ans;
	}
	else{
		cout<<max(ans+t[mid],ans1+t[mid1]);
	}
	return 0;
}
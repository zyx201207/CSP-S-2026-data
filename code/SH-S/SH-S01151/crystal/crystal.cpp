#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;

int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool ok1=1,ok2=1,ok3=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)	ok1=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])	ok2=0;
		if(a[i]<-500||a[i]>500)	ok3=0;
	}
	if(ok1){
		ll cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cnt+=i;
			if(cnt>m)	break;
			ans++;
		}
		cout<<ans+1<<'\n';
		return 0;
	}
	if(ok2){
		int ans=0;
		ll cnt=0,d=a[n]-a[n-1];
		while(cnt<m&&ans<n){
			ans++;
			cnt+=cnt+d;
		}
		cout<<ans+1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	if(ok3){
		int ans=0;
		for(int i=-500;i<=500;i++){
			int pos=upper_bound(a+1,a+n+1,i)-a-1,res=0;
			ll cnt=0;
			for(int j=pos;j>=1;j--){
				cnt+=i-a[j];
				if(cnt>m)	break;
				res++;
			}
			ans=max(ans,res);
		}
		cout<<ans<<'\n';
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ll cnt=0;
		int res=0;
		for(int j=i;j>=1;j--){
			cnt+=a[i]-a[j];
			if(cnt>m)	break;
			res++;
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}

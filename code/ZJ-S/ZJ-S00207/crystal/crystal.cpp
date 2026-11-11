#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans;
long long a[N];
int n;long long m;
bool check(int x,int m){
	int cnt=0;
	long long eren=m;
	for(int i=n;i>=1;i--){
		if(a[i]<=x){
			if(x-a[i]<=eren){
				cnt++;eren-=(x-a[i]);
			}
			else break;
			cout<<cnt;
		}
	}
//	cout<<cnt;
	if(cnt>=ans){
		ans=cnt;
		return true;
	}
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=1e12+3,r=-1e12-3;//猜nl
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(a[i],r);
		l=min(a[i],l);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long er=m;
		long long cnt=1;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<er){
				cnt++;
				er-=(a[i]-a[j]);
			}
		}
		ans=max(ans,cnt);
	//	cout<<ans;
	}
	/*while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid,m)){
			l=mid+1;
		}
		else r=mid-1;
	}
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid,m)){
			r=mid-1;
		}
		else l=mid+1;
	}*/
	cout<<ans;
	return 0;
}
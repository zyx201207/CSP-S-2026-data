#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,sum;
long long m,a[N],ans[N];
bool check(int x,int y){
	long long t=ans[y]-ans[x-1];
	if(1ll*(y-x+1)*a[y]-t<=m)return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans[i]=ans[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]*i-ans[i]<=m){
			sum=max(sum,i);
		}else{
			int l=1,r=i,t=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid,i))r=mid-1,t=mid;
				else l=mid+1;
			}if(t!=-1)sum=max(sum,i-t+1);
		}
	}
	cout<<sum;
	return 0;
}

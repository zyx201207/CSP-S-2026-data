#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long _,n,m,k,a[N],q[N],ans;
int main(){
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);//cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,now=0;
	for(int i = 1;i<=n;i++){
		if(i>1)
		now=now+(i-l)*(a[i]-a[i-1]);
		while(now>m){
			now-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}


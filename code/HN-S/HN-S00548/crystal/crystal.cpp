#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,i,cnt,num,ans=-1,a[N],d[N],k[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		num=k[i-1]+1;
		cnt=d[i-1]+(a[i]-a[i-1])*k[i-1];
		while(cnt>m){
			num--;
			cnt-=a[i]-a[i-num];
		}
		d[i]=cnt;
		k[i]=num;
		ans=max(ans,k[i]);
	}
	cout<<ans<<endl;
	return 0;
} 

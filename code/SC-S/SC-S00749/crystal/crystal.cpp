#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e8+10;
	ll n,m,a[N],mx=1e9,cnt=0;
int main(){ 
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
			if(a[i]>=a[i-1]){
			a[i]++;
			cnt++;
			m++;
			a[i]=cnt;
		}else if(a[i]<m&&a[i]<=0){
			a[i]++;
			a[i]+=cnt;
			cnt++;
		}else{
			continue;
		}
		a[i]+=a[i+1];
		mx=max(mx,max(cnt,a[i-1]));
	}
	cout<<cnt;
	return 0;
}

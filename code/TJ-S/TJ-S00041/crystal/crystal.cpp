#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],maxn=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll t=m,cnt=0;
		for(int j=1;j<=i;j++){
			if(t>=a[i]-a[j]){
				t-=a[i]-a[j];
				cnt++;
			}else{
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}

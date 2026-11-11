#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],f[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1073741824;j;j/=2){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=j&&f[i]==0)cnt++;
		}
		if(cnt>=m){
			ans+=j;
			for(int i=1;i<=n;i++){
				if(a[i]>=j&&f[i]==0)a[i]-=j;
				else f[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=j&&f[i]==0)a[i]-=j;
		}
	}
	cout<<ans;
	return 0;
}
/*
CCF have no egg！！！
十年OI一场空，不开long long见祖宗
感觉T3比T2简单……
*/
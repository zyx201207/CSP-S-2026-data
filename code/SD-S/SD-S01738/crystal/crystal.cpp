#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int f=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) f=0;
	}
	sort(a+1,a+1+n);
	if(f){
		for(int i=n;i>=1;i--){
			if(m>=(a[i-1]+a[1])*(i-1)/2){
				cout<<i<<"\n";
				return 0;
			}
		}	
	}else{
		int maxx=0;
		for(int i=n;i>=1;i--){
			ll zh=0;
			int kg=1;
			for(int j=i-1;j>=1;j--){
				if(zh>m){
					maxx=max(maxx,i-j-1);
					kg=0;
					break; 
				}
				zh+=a[i]-a[j];
			}
			if(kg){
				maxx=max(maxx,i);
				break;
			}
		}
		cout<<maxx<<"\n";
	}
	return 0;
}


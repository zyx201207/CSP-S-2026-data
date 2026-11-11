#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+5;
int n,a[N];
long long sum,ans,s[N],sd[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=1;--i){
		sd[i]=sd[i+1]+a[i];
	}
	long long i=1;
	int al=1,ar=n;
	long long aaa;
	if(sum%2==0) aaa=sum/2;
	else{
		aaa=sum/2+1;
	}
	while(i*2<=sum){
		if(s[al]-i+1>sd[ar]-i+1){
			if(c[al]!=c[ar]){
				ans+=min(aaa-i+1LL,sd[ar]-i+1LL);
			}
			i=sd[ar]+1;
			ar--;
		}
		else if(s[al]-i+1==sd[ar]-i+1){
			if(c[al]!=c[ar]){
				ans+=min(aaa-i+1LL,sd[ar]-i+1LL);
			}
			i=sd[ar]+1;
			ar--;
			al++;
		}
		else{
			if(c[al]!=c[ar]){
				ans+=min(aaa-i+1LL,s[al]-i+1LL);
			}
			i=s[al]+1;
			al++;
		}
	}
	cout<<ans;
	return 0;
}

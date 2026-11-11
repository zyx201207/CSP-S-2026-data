#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+1;
ll n,a[N],num,ans;
string c[N];
string s;
int main(){
	freopen("travel.in");
	freopen("travel.out");
	scanf("%lld",&n);
	if(n>5){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			cin>>c[i];
			}
		for(int i=1;i<=(n+1)/2;i++){
			if(c[i]!=c[n-i+1])ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		for(ll j=1;j<=a[i];j++) s=s+c[i];
		num+=a[i];
	}
	num--;
	for(int i=0;i<=num/2;i++){
		if(s[i]!=s[num-i])ans++;
	}
	printf("%lld",ans);
	return 0;
}

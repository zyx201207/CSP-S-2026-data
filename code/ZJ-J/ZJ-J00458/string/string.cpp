#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	long long t;
	cin>>t;
	for(long long i=0;i<t;++i){
		cin>>a[i]>>c[i];
	}
	long long ans=0,i=0,now=t-1;
	for(;;){
		while(a[i]>=a[now]){
			a[i]-=a[now];
			if(c[i]!=c[now])ans+=a[now];
			--now;
		}
		a[now]-=a[i];
		if(c[i]!=c[now])ans+=a[i];
		++i;
		if(i>=now)break;
	}
	cout<<ans;
}
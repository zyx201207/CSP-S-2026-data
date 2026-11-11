#include<bits/stdc++.h>
using namespace std;
int n;
long long l,ans;
long long a[200005];
char c[200005];
int f(long long x){
	long long sum=1;
	for(int i=1;i<=n;i++){
		if(sum>=x){
			return i;
		}
		sum+=a[i];
	}
	return n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	long long i=1,j=l-i+1;
	while(i<j){
		int ai=f(i),aj=f(j);
		if(c[ai]!=c[aj])ans+=min(a[ai],a[aj]);
		i+=min(a[ai],a[aj]);
		j-=min(a[ai],a[aj]);
	}
	cout<<ans<<endl;
	return 0;
}

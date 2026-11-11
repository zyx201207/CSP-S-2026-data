#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(a[i]<a[j]){
			if(c[i]!=c[j])ans+=a[i];
			a[j]-=a[i++];
		}
		else{
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j--];
		}
	}
	cout<<ans;
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long n,s[200005],ans,jishu,m,d[30],y[30],b[30];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	ans=s[n];
	for(long long i=n;i>=n-m;i--){
		ans=ans&s[i];
	}
	cout<<ans;
}

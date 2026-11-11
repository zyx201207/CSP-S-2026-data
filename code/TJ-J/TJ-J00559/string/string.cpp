#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],dq;
char c[200006];
char s[200006];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	dq=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=dq+1;j<=dq+a[i];j++){
			s[j]=c[i];
		}
		dq+=a[i];
	}
	int dq1=dq;
	if(dq%2==1)dq--;
	int mid=dq/2;
	int ans=0;
	for(int i=1;i<=mid;i++){
		if(s[i]!=s[dq1-i+1])ans++;
	}
	cout<<ans;
	return 0;
}

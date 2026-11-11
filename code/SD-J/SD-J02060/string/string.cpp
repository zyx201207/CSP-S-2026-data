#include<bits/stdc++.h>
#define int long long
using namespace std;
struct s{
	int a;
	char c; 
}b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i].a>>b[i].c;
	for(int l=1,r=n,i=1,j=b[n].a;l<=n/2&&r>=(n+2)/2;){
		if(b[l].c!=b[r].c)ans++;
		if(i==b[l].a)l++,i=1;
		else i++;
		if(j==1)r--,j=b[r].a;
		else j--;
	}
	cout<<ans;
	return 0;
}

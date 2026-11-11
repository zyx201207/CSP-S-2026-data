#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+20;
int n;
LL m,ans,cnt;
LL c[N],d[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) d[i]=c[i]-c[i-1];
	d[1]=0;
	for(int i=1;i<=n;i++){
		if(d[i]*(i-1)>m) break;
		ans=ans+d[i]*(i-1);
		if(ans<=m) cnt++;
		else break;
	}
	cout<<cnt<<endl;
	
	return 0;
} 

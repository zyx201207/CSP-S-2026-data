#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3fll
#define FINF 0xcfcfcfcfcfcfcfcfll
#define inf 0x3f3f3f3f
#define finf 0xcfcfcfcf
#define lowbit(x) (x & -x)
using namespace std;
const int maxn=5e5+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t;
int a[maxn];
int ans[maxn];
int st[maxn];
int top;
int b[maxn];
signed main()
{
	//	ios::sync_stdio_with(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card2.in","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
	top=0;
	for(int j=1;j<=m;j++)b[j]=0;
	for(int j=i;j<=n;j++){
		if(b[a[j]]){
			while(st[top]!=a[j])top--;
//			st[top]=a[i];
		}
		else st[++top]=a[j],b[a[j]]=1;
	}
	for(int j=1;j<=top;j++)ans[st[j]]++;
}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	
	return 0;
}


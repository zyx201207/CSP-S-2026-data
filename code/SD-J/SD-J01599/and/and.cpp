#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=2e5+10;
/*====================*/
int n,m;
int a[N];
/*====================*/
bool check(int W)
{
	int tot=0;
	for(int i=1;i<=n;i++)if((a[i]&W)==W)tot++;
	return tot>=m;
}
/*====================*/
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int now=0,step=30;
	while(step>=0)
	{
		now|=(1<<step);
		if(!check(now))now^=(1<<step);
		step--;
	}
	cout<<now<<endl;
	return 0;
}


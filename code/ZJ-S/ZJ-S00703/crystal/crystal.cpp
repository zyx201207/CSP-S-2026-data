#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,a[N];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int x;
    bool f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1) continue;
		else if(i==2) x=a[i]-a[i-1];
		else if(!f && a[i]-a[i-1]!=x) f=1;
    }
    if(!f)
    {
    	cout<<min(ll((x+sqrt(x*x+8*x*m))/(2.0*x)),n);
    	return 0;
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	int mm=m;
    	int j;
        for(j=i-1;j>=1;j--)
        {
        	if(a[i]-a[j]>mm)
        	{
        		break;
			}
			mm-=a[i]-a[j];
		}
		ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
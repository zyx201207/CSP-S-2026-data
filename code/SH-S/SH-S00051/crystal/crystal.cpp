#include<iostream>
#include<algorithm>
using namespace std;
using i64=long long;
const int N=5e5+5;
int n;
i64 m,a[N];
i64 pre[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
    	pre[i]=pre[i-1]+a[i];
	}
    int cur=1,ans=1;
    while (cur<=n)
    {
        int cnt=1;
        while (cur<n && a[cur]==a[cur+1])
        {
            cur++,cnt++;
        }
        int l=1,r=cur-cnt;//第一个满足条件的位置 
        while (l<r)
        {
        	int mid=(l+r)>>1;
        	if ((cur-cnt-mid+1)*a[cur]-(pre[cur-cnt]-pre[mid-1])<=m)
        	{
        		r=mid;
			}else
			{
				l=mid+1;
			}
		}
        ans=max(ans,cur-l+1);
        cur++;
    }
    cout<<ans<<"\n";
    return 0;
}

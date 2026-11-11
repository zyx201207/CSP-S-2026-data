#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N];
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n,ans=0;
	while(i<j)
    {
        if(a[i]>=a[j])
        {
            if(c[i]!=c[j])
            {
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }
            else
            {
                a[i]-=a[j];
                j--;
            }
        }
        else
        {
            if(c[i]!=c[j])
            {
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
            else
            {
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans;
	return 0;
}

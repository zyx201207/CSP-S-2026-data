#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[600000],cha[600000];
int main()
{
    freopen("crystal.in",r,stdin);
    freopen("crystal.out",w,stdout);
    ll n,m,ans=0,sum=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=i;j++)
                {
                    cha[j]=a[i]-a[j];
                    sum+=cha[j];
                    if(sum<=m)
                        {	
							ans=i;
						}
					else
                        break;
                }
        }
    for(ll s=ans;s<=n;s++)
		{
			if(a[s+1]==a[s])
				ans++;
			else
				break;
		} 
    cout<<ans;
    return 0;
}

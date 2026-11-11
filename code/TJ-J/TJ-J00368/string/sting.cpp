#include<bits/stdc++.h>
using namespace std;
long long n,a[300000],l=0,r=0,cnt=0,t;
char c[300000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    r=n-1;
    while(l<r)
    {
    	
        if(c[l]!=c[r])
        {
            t=min(a[l],a[r]);
            a[r]-=t;
            a[l]-=t;
            cnt+=t;
        }
        else
        {
        	
            t=min(a[l],a[r]);
            a[r]-=t;
            a[l]-=t;
		}
        if(a[l]==0)
        {
            l++;
        }
        if(a[r]==0)
        {
            r--;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}

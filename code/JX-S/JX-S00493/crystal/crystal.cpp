#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],s[500500];
int ans;
int dog(int n2)
{
        int l=1,r=n2;
        int mid=(l+r)/2;
        while(l<=r)
        {
		mid=(l+r)/2;
                int cnt=a[n2]*(n2-mid+1)-s[n2]+s[mid-1];
                if(cnt>m)l=mid+1;
                else if(cnt<=m&&cnt+a[n2]-a[mid-1]>m)
		{
			return n2-mid+1;
		}

                else r=mid-1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
                s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)
        {
                ans=max(ans,dog(i));
        }
        cout<<ans;

}

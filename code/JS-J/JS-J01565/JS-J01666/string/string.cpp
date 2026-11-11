#include <bits/stdc++.h>
using namespace std;
long long a[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r)
    {
        if(a[l]>a[r])
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]=a[l]-a[r];
            a[r]=0;
            r--;
        }
        else if(a[l]<a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]=a[r]-a[l];
            a[l]=0;
            l++;
        }
        else
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
	return 0;
}

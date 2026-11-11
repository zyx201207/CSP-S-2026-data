#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(c[l]!=c[r])
                sum+=a[l];
            a[r]-=a[l];
            l++;
        }
        else if(a[l]==a[r])
        {
            if(c[l]!=c[r])
                sum+=a[l];
            l++;
            r--;
        }
        else
        {
            if(c[l]!=c[r])
                sum+=a[r];
            a[l]-=a[r];
            r--;
        }
        cout<<sum<<endl;
    }
	return 0;
}

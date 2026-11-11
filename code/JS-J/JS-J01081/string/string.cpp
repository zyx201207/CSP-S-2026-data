#include<bits/stdc++.h>
using namespace std;
int n[200005];
char m[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int o;
	cin>>o;
	int ans=0;
	int l=1,r=o;
	for(int i=1;i<=o;i++)
    {
        cin>>n[i];
        cin>>m[i];
    }
    while(l<r)
    {
        if(m[l]==m[r])
        {
            if(n[l]>=n[r])
            {
                n[l]=n[l]-n[r];
                r=r-1;
            }
            else
            {
                n[r]=n[r]-n[l];
                l=l+1;
            }
        }
        else
        {
            if(n[l]>=n[r])
            {
                ans+=n[r];
                n[l]=n[l]-n[r];
                r=r-1;
            }
            else
            {
                ans+=n[l];
                n[r]=n[r]-n[l];
                l=l+1;
            }
        }
        //cout<<n[1]<<n[2]<<n[3]<<n[4]<<" "<<ans<<endl;
    }
    cout<<ans;
	return 0;
}

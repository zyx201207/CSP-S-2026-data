#includes<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main (void) {
    freopen("card.in","r");
    freopen("card.out","w");
    int n,m;
    cin>>n>>m;
    int t=0;
    int ans[10000]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        long long b[1000000];
        for(int j=i;j<=n;j++)
        {
            int p=0;
            for(int K=j;k<=n;k++)
            {
                if(a[k]==a[j])
                j==k;p=1;
            }
            if(p=0)
            {
                t++;
                b[t]==a[i];
            }
        }
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=t;k++)
            if(b[k]==j)
            {
                ans[j]++;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
	return 0;
}


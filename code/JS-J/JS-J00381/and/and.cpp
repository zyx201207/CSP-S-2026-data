#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;int a[200002];

    scanf("%d ",&n);scanf("%d ",&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    sort(a+1,a+n+1);

    if(m==1){//6

        cout<<a[n];//cout<<maxi;
        return 0;
    }

    if(m==n){//7

        int s=a[1];
        for(int i=2;i<=n;i++)
        {
            s=s&a[i];
        }

        cout<<s;
        return 0;
    }

    if(m==2){//8 9 10
        int maxi2=0;
        for(int i=1;i<=n;i++)
        {
             for(int j=i+1;j<=n;j++)
             {
                 int lins=a[i]&a[j];
                 maxi2=max(maxi2,lins);
             }

        }

        cout<<maxi2;
        return 0;
    }

    if(a[n]<4){//16 17
        int sum[5];
        for(int i=1;i<=n;i++) sum[a[i]]++;
        if(sum[3]>=m) cout<<3;
        else{
            m-=sum[3];
            if(m<=sum[2]) cout<<2;
            else if(m<=sum[1]) cout<<1;
            else cout<<0;
        }
        return 0;
    }

    else cout<<a[n-m+1];//13
    return 0;

}

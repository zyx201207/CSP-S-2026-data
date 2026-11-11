#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50050],b[50050];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,c,darkblack=0,d,i,j,h;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)    {
        for(j=0;j<=n;j++)
        {
            b[j]=0;
        }
        for(j=1;j<=i;j++)
        {
            b[i]=0;
            b[j]=a[i]-a[j];
        }
        sort(b+1,b+i+1);
        c=1;
        d=1;
        h=m;
        for(int j=1;j<=i;j++)
        {
            if(h>b[j])
            {
                h-=b[j];
                d++;
            }
            else{
                break;
            }
        }
        darkblack=max(d,darkblack);
    }
    cout<<darkblack;
    return 0;
}

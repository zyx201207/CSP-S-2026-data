#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n+10];
    int s[n+10][40],l,alive[n+10]={};
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=1;j<=n-i;j++)
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
    for(int i=1,J=0;i<=n;i++){
        for(int j=1;a[i]>0;a[i]/=2,J++,j++)
            s[i][j]=a[i]%2;
        if(i==1);
            l=J;
    }
    int top=l,ans[l+10]={};
    while(1)
    {
        int i=top;
        for(int flag=0;i>=1;i--){
            for(int j=1;j<=n;j++)
                if(s[j][i]==1&&alive[j]==0)
                    flag++;
            if(flag>=m){
                top=i;
                ans[i]=1;
                break;
            }
        }
        if(i==0)
            break;
        for(int i=1;i<=n;i++)
            if(s[i][top]!=1)
                alive[i]=1;
    }
    int pj=0;
    for(int i=1;i<=l;i++)
        pj+=ans[i]*pow(2,i-1);
    cout<<pj;

    return 0;
}

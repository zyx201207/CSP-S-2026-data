# include<bits/stdc++.h>
using namespace std;
bool f;
int n;
long long m,a[500005],cha[500005],mincha=1e12,ans,w[10005][10005],mp[500005],k;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    for(int i=2;i<=n;i++)
    {
        if(i==2)k=a[i]-a[i-1];
        else {
            if(a[i]-a[i-1]!=k)f=true;
        }
        cha[i]=a[i]-a[i-1];
        mincha = min(cha[i],mincha);
    }
    if(m<mincha){
        cout<<1;
        return 0;
    }
    if(f==false){
        long long e=0;
        for(int i=1;i<=n-1;i++){
            e+=k*i;
            if(e>m){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }

    /*while(j<=n)
    {
        int cnt=1,sum=0;
        for(int k=i+1;k<=j;k++){
            sum+=c[k]*cnt;
            cnt++;
        }
        if(sum<=m){
            i++;
            j++;
        }

    }*/
    memset(mp,0X7F,sizeof(mp));
    for(int i=1;i<=n;i++)w[i][i]=0;
    for(int i = 1; i<n;i++)
    {

        for(int j=i+1;j<=n;j++)
        {
            w[i][j]=w[i][j-1]+cha[j]*(j-i);
            mp[j-i]=min(mp[j-i],w[i][j]);
        }
    }
    for(int i=n-1;i>=1;i--){
        if(mp[i]<=m){
            cout<<i+1;
            return 0;
        }
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],new_a[500005],cha_a[500005],ch,xm,ans,num[100005],fnum[100005],l,z,maxn,ians,cost;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //n>5000 A+B
    if(n>5000)
    {
        ch=a[2]-a[1];
        xm=floor(m/ch);
        ans=((sqrt(8*xm+1)-1)/2)+1;
        ans=min(ans,n);
        cout<<ans;
        return 0;
    }
    //n<=5000
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)num[a[i]]++;
        else if(a[i]==0)l++;
        else if(a[i]<0)fnum[0-a[i]]++;
    }
    z=1;
    for(int i=100000;i>=1;i--)
    {
        for(int j=1;j<=num[i];j++)
        {
            new_a[z]=i;
            z++;
        }
    }
    for(int i=1;i<=l;i++)
    {
        new_a[z]=0;
        z++;
    }
    for(int i=1;i<=100000;i++)
    {
        for(int j=1;j<=fnum[i];j++)
        {
            new_a[z]=-i;
            z++;
        }
    }
    cha_a[1]=0;
    maxn=new_a[1];
    for(int i=2;i<=n;i++)
    {
        cha_a[i]=cha_a[i-1]+new_a[i-1]-new_a[i];
        //cout<<cha_a[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        ians=0;
        cost=0;
        for(int j=i;j<=n;j++)
        {
            cost+=cha_a[j]-cha_a[i];
            if(cost<m)ians=j-i+1;
            //cout<<ians<<" ";
        }
        ans=max(ians,ans);
    }
    cout<<ans;
    return 0;
}

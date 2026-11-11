#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
long long w[MAX],del[MAX];
long long n,m;
//---------------------------------

//---------------------------------
long long dfs(long long l,long long r,long long p,long long ans)
{
    if(p==0)
    {

        return ans;
    }
    if(l==1&&r==n)
    {
        //---------------------------------
        //cout<<"\n I'm "<<l<<" to "<<r<<" ,and my power is "<<p<<" ,now ans is "<<ans<<"\n";
        //---------------------------------
        if(p!=0)
        {
            return ans-1;
        }
        else
        {
            return ans;
        }
    }
    if(l==1)
    {
        if((r-l+1)*(w[r+1]-w[r])<=p)
        {
            p-=(r-l+1)*(w[r+1]-w[r]);
            w[r]=w[r+1];
            return dfs(l,r+1,p,ans+1);
        }
        return ans;
    }
    if(r==n)
    {
        if(ans==n)
        {
            return n-1;
        }
        if(w[l]-w[l-1]>p)
        {
            return ans;
        }
        p-=(w[l]-w[l-1]);
        w[l-1]=w[l];
        return dfs(l-1,r,p,ans+1);
    }
    long long minr=(w[r+1]-w[r])*(r-l+1),minl=w[l]-w[l-1];
    if(minr>p)
    {
        if(minl>p)
        {
            return ans;
        }
        p-=minl;
        w[l-1]=w[l];
        return dfs(l-1,r,p,ans+1);
    }
    if(minl>p)
    {
        if(minr>p)
        {
            return ans;
        }
        p-=minr;
        w[r+1]=w[r];
        return dfs(l,r+1,p,ans+1);
    }
    if(minr<minl)
    {
        p-=minr;
        w[r+1]=w[r];
        return dfs(l,r+1,p,ans+1);
    }
    p-=minl;
    w[l-1]=w[l];
    return dfs(l-1,r,p,ans+1);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int flag=0;
    cin>>w[1];
    long long  maxw=w[1];
    for(long long  i=2;i<=n;i++)
    {
        cin>>w[i];
        maxw=max(maxw,w[i]);
        if(w[i]!=w[i-1])
        {

            flag=1;
        }
    }
    if(flag==0)
    {

        cout<<n-1<<"\n";
        return 0;
    }
    sort(w+1,w+n+1);

    //----------------------------
    long long mindel=maxw,no=0;
    for(long long i=2;i<=n;i++)
    {

        del[i]=w[i]-w[i-1];

        //------------------------------------
        //cout<<del[i]<<' ';

        //------------------------------------

        if(del[i]<mindel)
        {
            mindel=del[i];
            no=i;
            //---------------------------------
            //cout<<endl<<"no.clear   no.push_back("<<i<<") mindel update to"<<del[i]<<"\n";
            //---------------------------------
        }

    }
    //------------------------------------
    //cout<<endl<<endl;
    //for(int i=0;i<no.size();i++)
    //{
        //cout<<no[i]<<' ';
    //}
    //cout<<endl;
    //------------------------------------




    cout<<dfs(no,no,m,1)<<"\n";
    return 0;
}

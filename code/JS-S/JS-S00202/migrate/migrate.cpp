# include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];/*
struct node{
    long long st,ed,step;
}

void bfs(long long st,long long ed)
{
    //if(x[ed]-x[st]<=d)return 1;
    queue<node>q;
    for(int i=st;i<=ed;i++)
    {
        for(int j=i+1;j<=ed&&;j++)
    }
}*/

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        long long k;
        bool f=false;
        cin>> n>> d>>x[1];
        for(int i=2;i<=n;i++){
            cin>>x[i];
            if(i==2)k=x[i]-x[i-1];
            else {
                if(k!=x[i]-x[i-1])f=true;
            }
        }
        if(x[n]-x[1]<=d){
            cout<<0<<endl;
            continue;
        }
        if(f==false)
        {
            if(k>=d&&k<2*d)cout<<0<<endl;
            else cout<<n-2*d<<endl;
        }/*
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n&& x[j]-x[i]>=d;i++){
                bfs(i,j);
            }
        }*/
    }



    return 0;
}

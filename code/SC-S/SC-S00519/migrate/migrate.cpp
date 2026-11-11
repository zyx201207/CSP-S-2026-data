#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> m;vector<vector<int>> cm;
vector<int> x;
int flyd(int u,int v,int d)
{
    if(v-u==1&&x[v]-x[u]>d){return -2177777;}
    if(x[v]-x[u]<=d){return 1;}
    else{
        return flyd(u,u+2,d)+flyd(u+2,v,d);
    }
}
int flyz(int u,int v,int d)
{
    if(v-u==1&&x[v]-x[u]>d){return -2177777;}
    if(x[v]-x[u]<=d){return 1;}
    else{
        return flyz(u,u+1,d)+flyz(u+1,v,d);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int in;int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>in;
            x.push_back(in);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            //if(flyd(i,j,d)==flyz(i,j,d)){ans++;}
            if((x[i]-x[j])%d!=0&&x[i]-x[j]>d){ans++;}
        }
        cout<<ans+1<<endl;
    }
    return 0;
}

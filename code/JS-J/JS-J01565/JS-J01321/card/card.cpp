#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int s[N];
int sj[N];
map<int,int>in;
map<int,bool>mp;
map<int,int>mp2;
stack<int> b;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        //mp2[a[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {
        //cout<<"Push "<<a[i]<<'\n';
        if(mp[a[i]]==1)
        {
            //cout<<"ERR!"<<'\n';
            int end=a[i],f=1;
            while(f==1&&!b.empty())
            {
                if(b.top()==end) f=0;
                int now=b.top();
                b.pop();
                //int ni=mp2[now];
                //cout<<"  pop"<<now<<'\n';
                //s[now]--;
                s[now]+=i-in[now];
                //cout<<"  from"<<in[now]<<"~"<<i-1;
                //cout<<"  ,  +"<<i-in[now]<<'\n';
                if(now!=a[i]) in[now]=0;
                else in[now]=i;
                mp[now]=0;
            }
            //in[a[i]]=i;
        }
        mp[a[i]]=1;
        if(!in[a[i]])
        {
            //cout<<"new: in["<<a[i]<<"]="<<i<<'\n';
            in[a[i]]=i;
        }
        b.push(a[i]);    
        // cout<<"in: ";
        // for(int i=1; i<=m; i++) cout<<in[i]<<" ";
        // cout<<'\n';
        // cout<<"s: ";
        // for(int i=1; i<=m; i++) cout<<s[i]<<" ";
        // cout<<'\n';
        
    }
    for(int i=1; i<=m; i++)
    {
        int add=0;
        if(in[i]) add=n-in[i]+1;
        cout<<s[i]+add<<" ";
    }
    cout<<'\n';
    return 0;
}
/*
g++ card.cpp -std=c++14 -O2 -w -o card
./card
*/


/*
check:
1. a[][]
2. freopen("card.in","r",stdin);
3. freopen("card.out","w",stdout);
4. long long
5. shu ju fan wei
6. //Debug
*/
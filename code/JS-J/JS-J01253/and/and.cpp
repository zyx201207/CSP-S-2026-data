#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int N;
long long z[200005];
string s[200005];
string ans;
bool va[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int q=1;q<=n;q++)
    {
        cin>>z[q];
        while(z[q]!=0)
        {
            if(z[q]%2==0) s[q]='0'+s[q];
            else s[q]='1'+s[q];
            z[q]/=2;
        }
        int as=s[q].size();
        N=max(N,as);
    }
    for(int q=1;q<=n;q++)
    {
        while(s[q].size()<N)
        {
            s[q]='0'+s[q];
        }
    }
    for(int q=0;q<N;q++)
    {
        cnt=0;
        vector<int> wa;
        for(int w=1;w<=n;w++)
        {
            if(va[w]==1)continue;
            if(s[w][q]=='1')
            {
                cnt++;
            }
            else wa.push_back(w);
        }
        if(cnt>=m)
        {
            ans='1'+ans;
            for(int i:wa)
            {
                va[i]=1;
            }
        }
        else ans='0'+ans;
    }
    long long Ans=0;
    for(int q=0;q<=ans.size();q++)
    {
        if(ans[q]=='1')Ans+=pow(2,q);
    }
    cout<<Ans;
    return 0;
}

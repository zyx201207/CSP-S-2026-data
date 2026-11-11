#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int> ca;
int m,n,a[N],cnt[N];
void fun1()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=1;
    for(;x<=n;x++)
    {
        for(int i=0;i<ca.size();i++) ca.pop_back();
        int s[N]={-1};
        for(int i=x;i<=n;i++)
        {
            ca.push_back(a[i]);
            if(s[a[i]]==-1) s[a[i]]=ca.size()-1;
            else
            {
                for(int j=s[a[i]];j<ca.size()-1;j++) ca.pop_back();
                for(int j=1;j<=m;j++)
                {
                    if(s[j]>=ca.size()) s[j]=-1;
                }
            }
        }
        for(int i=0;i<ca.size();i++) cnt[ca[i]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    fun1();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=5e5+5;
int a[MAXN];
int cnt[MAXN];
vector<int> v;
void do_A()
{
    cnt[m]=n;
    for(int i=n-1;i>0;i--)
    {
        if(cnt[a[i]]!=0) continue;
        else cnt[a[i]]=i;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    //for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    //cout<<endl;
    bool flaga=true;
    for(int i=2;i<=n;i++) if(a[i]<a[i-1]) flaga=false;
    if(flaga) do_A();
    else
    for(int i=1;i<=n;i++)
    {
        v.clear();
        for(int j=i;j<=n;j++)
        {
            for(int k=v.size()-1;k>-1;k--)
            {
                if(v[k]==a[j])
                {
                    //cout<<"dfgfg"<<k<<"dfd";
                    v.erase(v.begin()+k,v.end());
                    //for(auto x:v) cout<<x<<' ';
                    //cout<<endl;
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(auto x:v) cnt[x]++;
        //for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
        //cout<<endl<<endl;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

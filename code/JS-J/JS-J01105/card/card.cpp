#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],ans[300010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cnt[m+1];
    vector<int> pai;
    for(int i=0;i<n;i++)
    {
        memset(cnt,-1,sizeof(cnt));
        pai.clear();
        for(int j=i;j<n;j++)
        {
            if(cnt[a[j]]!=-1)
            {
                int nn=pai.size(),k;
                for(k=cnt[a[j]];pai.size()>k;)
                    cnt[pai[k]]=-1,pai.erase(pai.begin()+k);
                cnt[a[j]]=k;
                pai.push_back(a[j]);
            }
            else
                cnt[a[j]]=pai.size(),pai.push_back(a[j]);
        }
        for(int j=0;j<pai.size();j++)
            ans[pai[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}

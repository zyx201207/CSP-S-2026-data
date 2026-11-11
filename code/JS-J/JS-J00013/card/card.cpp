#include<iostream>
#include<vector>
using namespace std;

int n,m;
int a[500010];
int ans[300010];

void dfs(int l)
{
    vector<int> v;
    for(int j=l;j<=n;j++)
    {
        int wei=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==a[j])
            {
                wei=i;
                break;
            }
        }
        if(wei!=-1)
        {
            int len=v.size();
            for(int i=wei;i<len;i++)
                v.pop_back();
        }
        v.push_back(a[j]);
    }
    for(int i=0;i<v.size();i++)
        ans[v[i]]++;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        dfs(i);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

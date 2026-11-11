#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],pre[500001];
map<int ,int>mp;
bool flag[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        flag[i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++){
            if(a[i]==a[j]&&i!=j){
            for(int k=i+1;k<=j;k++)
            {
                flag[k]=false;
            }
        }
            else
            {
                for(int k=i;k<=j;k++)
                {
                    if(flag[k]==true)
                    {
                        mp[a[k]]++;
                    }
                }
            }
    }
    for(int i=1;i<=n;i++)
            {
                flag[i]=true;
            }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<mp[m]<<" ";
    }
return 0;
}

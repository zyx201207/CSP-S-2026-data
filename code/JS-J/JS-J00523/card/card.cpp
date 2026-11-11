#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int last_id[300005];
int cnt[300005];
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
            for(int j=1;j<=m;j++)
            {
                //cout<<last_id[a[i]]<<" "<<last_id[j]<<" "<<i<<" "<<j<<endl;
                if(last_id[a[i]]&&last_id[j]<last_id[a[i]]&&last_id[j]>i)
                {
                    last_id[j]=0;
                    //cout<<6;
                }
                int t=last_id[a[i]];
                last_id[a[i]]=i;
                if(last_id[j])
                {
                    cnt[j]++;
                    //cout<<"cnt_"<<j<<"++;";
                }
                last_id[a[i]]=t;
            }
            //cout<<endl;
            last_id[a[i]]=i;

        // for(int j=1;j<=m;j++)
        //     cout<<last_id[j]<<" ";
        // cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
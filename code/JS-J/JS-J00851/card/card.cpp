#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500007;
int n,m,a[N],ans[N];
void print(){
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int>t[300007];
        for(int j=i;j<=n;j++){
            if(t[a[j]].empty())t[a[j]].push_back(j);
            else{
                int lst=t[a[j]][t[a[j]].size()-1];
                for(int k=j;k>=lst;k--)if(!t[a[k]].empty())t[a[k]].pop_back();
                t[a[j]].push_back(j);
            }
        }
        for(int j=1;j<=m;j++){
            if(!t[j].empty())ans[j]++;
        }
    }
    print();
    return 0;
}
/*
Think:

1211123112
0111211

        vector<int>t[300007];
        for(int j=i;j<=n;j++){
            if(t[a[j]].empty())t[a[j]].push_back(j);
            else{
                int lst=*t[a[j]].end();
                for(int k=j;k>=lst;k--)if(!t[a[k]].empty())t[a[k]].pop_back();
                t[a[j]].push_back(j);
            }
        }
        for(int j=1;j<=m;j++){
            if(!t[j].empty())ans[j]++;
        }
*/

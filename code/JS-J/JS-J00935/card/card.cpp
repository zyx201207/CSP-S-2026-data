#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],cnt[M],ans[M];
vector<int> v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int k=1;k<=n;k++){
        v.clear();
        for (int i=1;i<=m;i++)
            cnt[i]=0;
        for (int i=k;i<=n;i++){
            if (cnt[a[i]]==1)
                while(!v.empty()&&v[v.size()-1]!=a[i])
                    cnt[v[v.size()-1]]--,v.pop_back();
            else
                v.push_back(a[i]),cnt[a[i]]++;
        }
        for (auto i:v)
            ans[i]++;
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}

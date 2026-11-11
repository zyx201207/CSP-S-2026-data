#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
vector<int> v,v1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        v.clear();v1.clear();
        v.push_back(a[i]);
        v1=v;
        for(int j=i+1;j<=n;j++){
            bool f=0;
            for(int k=0;k<v.size();k++){
                if(a[j]==v[k]&&f==0){
                    v.clear();
                    for(int cc=0;cc<=k;cc++){
                        v.push_back(v1[cc]);
                    }
                    f=1;
                }
            }
        }
        for(auto it:v){

            cnt[it]++;
        }

    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}

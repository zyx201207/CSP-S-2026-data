#include <bits/stdc++.h>
using namespace std;
constexpr int N=500005,M=300005;
int n,m;
int c[N],l[M];
pair<int,int> fr[N];
long long mul[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>c[i];
        mul[i]=1;
    }
    for (int i=n-1;i>=0;i--){
        if (l[c[i]]==0){
            fr[i]={i+1,c[i]};
        }else{
            fr[i]={l[c[i]],0};
        }
        l[c[i]]=i;
    }
    for (int i=0;i<n;i++){
        mul[fr[i].first]+=mul[i];
        ans[fr[i].second]+=mul[i];
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i];
        if (i!=m)cout<<' ';
    }
    cout<<'\n';
    return 0;
}

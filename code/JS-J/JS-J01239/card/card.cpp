#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<utility>
using namespace std;
using pii=pair<int,int>;
int main(){
    #ifndef PSD
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int&i:a)cin>>i;
    auto a1=a;
    sort(a1.begin(),a1.end());
    vector<long long> cnt(m+1);
    if(a==a1){
        vector<int> tmp(m+5);
        for(int&i:a)++tmp[i];
        vector<pii> p;
        for(int i=1;i<=m;i++)if(tmp[i])
            p.emplace_back(i,tmp[i]);
        int sum=0;
        for(auto&i:p){
            sum+=i.second;
            cnt[i.first]=sum;
        }
        for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
        return 0;
    }
    vector<int> last(m+5);
    for(int i=0;i<n;i++)last[a[i]]=max(last[a[i]],i);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j=last[a[j]]+1)
            ++cnt[a[j]];
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';

    return 0;
}

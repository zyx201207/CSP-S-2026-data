#include<bits/stdc++.h>
using namespace std;
int n, m, card[300005], a[500005];
vector<int> v;
void FounD(int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            for(int j=1;j<v.size()-i+1;j++) v.pop_back();
            v.push_back(x);
            return;
        }
    }
    v.push_back(x);
    return;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            FounD(a[j]);
        }
        for(int j=0;j<v.size();j++){
            card[v[i]]++;
        }
        while(v.empty()!=1) v.pop_back();
    }
    for(int i=1;i<=m;i++) cout<<card[i]<<" ";
    return 0;
}

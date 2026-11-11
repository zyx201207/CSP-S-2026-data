#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt[300005],a[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> v;
    for(int i=n-1;i>=0;i--){
       if(find(v.begin(),v.end(),a[i])!=v.end()){
         vector<int> idx;
        int k=0;
        for(k=0;k<v.size();k++){
            if(v[k]!=a[i])idx.push_back(v[k]);
            else break;
        }
        v.clear();
        for(k=0;k<idx.size();k++)v.push_back(idx[k]);
       }
        v.push_back(a[i]);
        for(int i=0;i<v.size();i++)cnt[v[i]]++;
    }
    for(int i=1;i<=m;i++)cout << cnt[i] <<" ";
    return 0;
}

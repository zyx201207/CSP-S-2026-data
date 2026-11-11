#include<bits/stdc++.h>
using namespace std;
int t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for(int i=1;i<=n;i++){
        set<int>s;
        for(int k=i;k<=n;k++){
            if(s.count(a[k])){
                auto p=s.lower_bound(a[k]);
                for(int j=*p+1;j<=s.size();j++) s.erase(j);
            }
            s.insert(a[k]);
        }
        for(int j=1;j<=m;j++)
            if(s.count(j)) t[j]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    cout<<endl;
    return 0;
}

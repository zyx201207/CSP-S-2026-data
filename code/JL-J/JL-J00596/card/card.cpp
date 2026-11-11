#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> a,b;
bool check(int as){
    for(int i=0;b[i];i++){
        if(b[i]==as){
            return 1;
        }
    }
    return 0;
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int as=0;
        cin>>as;
        a.push_back(as);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check(a[j])==0)
            b.push_back(a[j]);
            else{
                for(int k=j;k<=n;k++){
                   b.erase(b.begin()+k);
                }
                b.push_back(a[j]);
            }
            if(check(i)){
                ans++;
            }
        }
        b.clear();
        cout<<ans<<' ';
        ans=0;
    }
}

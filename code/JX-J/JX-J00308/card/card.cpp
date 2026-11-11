#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k,j=1,ans[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    k=n;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            f=false;
        }
    }
    if(f){
        for(int i=1;i<=m;i++){
            if(a[i]==i) cout<<n<<" ";
            else cout<<0<<" ";
        }
        return 0;
    }
    while(k--){
        long long bj[300005]={};
        for(int i=j;i<=n;i++){
            s.push(a[i]);
            bj[a[i]]++;
            if(bj[a[i]]>1){
                bj[a[i]]--;
                s.pop();
                while(s.top()!=a[i]){
                    s.pop();
                }
            }
        }
        j++;
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

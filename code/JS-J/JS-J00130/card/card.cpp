#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        cout<<n<<' '<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> q;
    int ans[N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            while(q.back()!=a[j]) q.pop_back();
            q.push_back(a[j]);
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=q.size();k++){
                if(q[k]==j) ans[j]=i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return  0;
}

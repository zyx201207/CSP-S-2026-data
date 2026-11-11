#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+1;
const int M=3e5+1;
int a[N],cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int line=i;
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[k]==a[j]) line=k;
            }
        }
        for(int k=1;k<=m;k++){
            for(int j=line;j<=n;j++){
                if(a[j]==k) cnt[k]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}

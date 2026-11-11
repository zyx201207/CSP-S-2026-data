#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int ans[500001];
int b[500001];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int w=1;
        for(int j=i;j<=n;j++){
            int f=0;
            for(int k=1;k<=w;k++)
                if(b[k]==a[j])
                    f=k;
            if(f!=0){
                for(int k=f;k<=w;k++)
                    b[k]=0;
                w=f;
            }
            b[w]=a[j];
            w++;
        }
        w--;
        for(int j=1;j<=w;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10; 
int n,m;
int a[N],b[N],c[M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++){
        int idx=0;
        for (int j=i;j<=n;j++){
            for (int k=1;k<=idx;k++){
                if(a[j]==b[k]){
                    idx=k-1;
                    break;
                }
            }
            b[++idx]=a[j];
        }
        for (int j=1;j<=idx;j++){
            c[b[j]]++;
        }
    }
    for (int i=1;i<=m;i++)cout<<c[i]<<" ";
    return 0;
}
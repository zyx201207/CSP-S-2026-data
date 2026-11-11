#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],cnt[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int id=i;
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            for(int k=id;k<j;k++){
                if(a[j]==a[k]){
                    for(int l=k;l<j;l++){
                        cnt[a[l]]--;
                    }
                    id=j;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}

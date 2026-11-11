#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300005],a[500005];
int st[500005],top;
void turn(int p){
    top=0;
    for(int i=p;i<=n;i++){
        for(int j=1;j<=top;j++){
            if(st[j]==a[i]){
                top=j-1;
                break;
            }
        }
        st[++top]=a[i];
    }
    for(int i=1;i<=top;i++){
        cnt[st[i]]++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        turn(i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

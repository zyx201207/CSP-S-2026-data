#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[1000000],ans[1000000],b[1000000];
int abb(int x){
    for(int i=1;i<=cnt-1;i++){
        if(x==b[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=1;
        for(int j=i;j<=n;j++){
            int r=abb(a[j]);
            if(r==-1){
                b[cnt]=a[j];
                cnt++;
            }
            else{
                for(int i=r+1;i<=cnt;i++){
                    b[i]==0;
                }
                cnt=r+1;
            }
        }
        for(int k=1;k<=cnt-1;k++){
            ans[b[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

#include<iostream>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        if(n%2){
            cout<<(n+1)/2;
        }else{
            cout<<n/2;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(a[j]==a[j+1])j+=2;
            else {
                ans[a[j]]++;j++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

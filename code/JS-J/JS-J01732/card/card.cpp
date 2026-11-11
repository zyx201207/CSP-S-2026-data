#include<bits/stdc++.h>
using namespace std;
int a[5005];
int m;
int ans[3005];
int c[5005];
void f(int n){
    int t[5005];
    for(int i=1;i<=n;i++){
        if(t[a[i]]){
            c[t[a[i]]]=i;
        }
        t[a[i]]=i;
    }
}
void x(int n){
    bool t[5005];
    for(int i=0;i<=n+1;i++){
        t[i]=true;
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=0&&c[i]<=n&&t[c[i]]&&t[i]){
            for(int j=i;j<=c[i];j++){
                t[j]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(t[i]){
            ans[a[i]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        x(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
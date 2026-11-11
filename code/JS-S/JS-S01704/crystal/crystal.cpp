#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    int a[500005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        int b=0,ss=0;
        for(int j=0;j<n;j++){
            if(a[j]<=a[i]){
                b+=i-a[j];
                ss++;
            }
        }
        if(b<=m){
            s=max(ss,s);
        }
    }
    cout<<s;
    return 0;
}

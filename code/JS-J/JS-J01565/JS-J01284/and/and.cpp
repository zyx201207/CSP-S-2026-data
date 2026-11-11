#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145140],p[1145140],maxn,z;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        z=a[1];
        for(int i=2;i<=n;i++){
            z=z&a[2];
        }
        cout<<z;
        return 0;
    }else if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    for(int q=1;q<=m;q++){
        for(int i=1;i<=n;i++){
            if(q!=i){
                maxn=max(maxn,q%i);
            }
        }
    }
    cout<<maxn;
    return 0;
}
//\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/%%%
//please help me RP++

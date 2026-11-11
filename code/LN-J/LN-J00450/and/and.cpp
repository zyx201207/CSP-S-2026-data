#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001],MaX=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        }

    if(m==1)for(int i=1;i<=n;i++){
        if(a[i]>MaX)MaX=a[i];
    }
    if(m==n){
        MaX=0;
            for(int i=1;i<=n;i++){
        MaX=MaX|a[i];
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]|a[j]>MaX)MaX=a[i]|a[j];
        }
    }
    cout<<MaX;
return 0;
}

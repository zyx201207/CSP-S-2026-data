#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans[200010],b[200010],d,f,s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    d=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(a[i],s);
    }
    while(d--){

            f++;
            for(int j=1;j<=n;j++){
                b[j]=a[j];
            }

        for(int i=f;i<=n;i++){
            for(int j=i;j>=f;j--){
            if(b[j]==b[i]&&b[i]!=-1){
                for(int k=j;k<i;k++){
                    b[k]=-1;
                }

        }
    }
        }

    for(int i=f;i<=n;i++){
        if(b[i]!=-1){
            ans[b[i]]++;
        }
    }
    }
    for(int i=1;i<=s;i++){
            if(ans[i]!=0){
        cout<<ans[i]<<" ";
    }
    }
    return 0;
}

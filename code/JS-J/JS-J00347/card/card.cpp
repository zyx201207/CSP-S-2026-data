#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],c[555555];
struct st{
    int be;
    int en;
};
st v[555555];
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(v[a[i]].be==0) v[a[i]].be=i;
        else v[a[i]].en=i;
    }
    if(m<=2){
        c[a[n]]=1;
        for(int i=1;i<=m;i++){
            cout<<c[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(v[a[j]].en!=0&&v[a[j]].en!=i){
                c[a[j]]++;
                j=v[a[j]].en;
            }else{
                c[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

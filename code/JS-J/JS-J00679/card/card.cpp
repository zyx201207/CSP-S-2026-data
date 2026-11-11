#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],f[300010],s[300010];
bool f1=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!(a[i-1]<=a[i])){
            f1=0;
        }
    }
    if(f1){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
        return 0;
    }else if(m==1){
        cout<<n;
        return 0;
    }else if(m==2){
        int z=0,b=0;
        if(a[n]==1)z=n;
        else b=n;
        for(int i=1;i<=n;i++){
            if(a[i]==1&&z!=n)z++;
            else if(a[i]==2&&b!=n)b++;
        }
        cout<<z<<" "<<b;
        return 0;
    }
    int k=1;
    for(int i=1;i<=n;i++){
        k=1;
        memset(f,0,sizeof f);
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                f[a[j]]=k;
                b[k]=a[j];
                k++;
            }else{
                k=f[a[j]];
                for(int i=1;i<=m;i++){
                    if(f[i]>k)f[i]=0;
                }
                k++;
            }
        }
        for(int i=1;i<=m;i++){
            if(f[i]){
                s[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}

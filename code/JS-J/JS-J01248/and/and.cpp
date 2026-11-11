#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],h[40],ans;
long long b[200010][40],c[200010],yc[200010],nb,aw[200010],nen;
void solve(){
    h[0]=1;
    for(int i=1;i<=30;i++){
        h[i]=h[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        long long x=a[i];
        for(int j=30;j>=0;j--){
            if(x>=h[j]){
                x-=h[j];
                b[i][j]=1;
            }
            if(x==0)break;
        }
    }
    for(int j=30;j>=0;j--){
        int num=0,sum=0,sn=nb;
        for(int i=1;i<=n;i++){
            if(b[i][j])c[++num]=i;
        }
        sum=num;
        if(sum>=m&&nb==0){
            nb=num;
            for(int i=1;i<=num;i++){
                yc[i]=c[i];
            }
            ans+=h[j];
        }
        else if(sum>=m){
            int ls=1,ln=1;
            nen=0;
            for(int i=1;i<=nb;i++){
            }
            while(ls<=num){
                while(ln<nb&&yc[ln]<c[ls])ln++;
                if(yc[ln]==c[ls]){
                    aw[++nen]=c[ls];
                }
                ls++;
            }
            if(nen>=m){
                ans+=h[j];
                for(int i=1;i<=nen;i++){
                    yc[i]=aw[i];
                }
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    cout<<ans;
    return 0;
}

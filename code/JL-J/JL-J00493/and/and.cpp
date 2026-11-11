#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],maxa,ance,b[200000],mixa;
bool p;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int q;
        scanf("%d",&q);
        a[q]++;
        b[i]=q;
        if(mixa==0){
            mixa=q;
        }else{
            if(mixa>q){
                mixa=q;
            }
        }
        if(q>maxa){
            maxa=q;
        }
    }
    if(m==1){
        cout<<maxa;
        return 0;
    }
    if(maxa==4){
        if(a[4]>=m){
            cout<<'4';
            return 0;
        }
        if(a[3]>=m){
            cout<<'3';
            return 0;
        }
        if(a[2]>=m){
            cout<<'2';
            return 0;
        }
        if(a[1]>=m){
            cout<<'1';
            return 0;
        }
    }
    if(m+1==n){
        for(int i=1;i<=n;i++){
            if(p||mixa!=b[i]){
                maxa=maxa&b[i];
            }
            if(mixa==b[i]){
                p=1;
            }
        }
        cout<<maxa;
        return 0;
    }
    for(int i=1;i<=maxa;i++){
        if(a[i]>0){
            for(int j=i;j<=maxa;j++){
                if((i!=j&&a[j]>0)||(i==j&&a[j]>1)){
                    int z=i&j;
                    if(z>ance){
                        ance=i&j;
                    }
                }
            }
        }
    }
    cout<<ance;
    return 0;
}

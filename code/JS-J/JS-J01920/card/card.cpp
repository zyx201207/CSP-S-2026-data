#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[300001],b[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n-1;i++){
        for(int j=1;j<=n;j++)b[i]=0;
        b[i+1]=a[i+1];
        int cnt=2;
        for(int j=i+1;j<=n;j++){
            bool f=1;
            for(int k=1;k<=cnt-1;k++){
                if(b[k]==a[j]){
                    for(int d=k;d<=cnt-1;d++){
                        b[d]=0;
                    }
                    b[k]=a[j];
                    cnt=k+1;
                    f=0;
                    break;
                }
            }
            if(f){b[cnt]=a[j];cnt++;}
        }
        for(int j=1;j<=cnt-1;j++){
            s[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}

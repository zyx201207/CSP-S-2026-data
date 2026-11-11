#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],tong[200005][200005]={0},ans2;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<sizeof(a);i++){
        for(int j=0;j<sizeof(a);j++){
            tong[i][j]=a[j];
        }
    }

    if(m==1){
        for(int i=0;i<sizeof(a);i++){
            for(int j=0;j<sizeof(a)-1;j++){
                if(a[j]>a[j+1]){
                    int w=a[j];
                    a[j]=a[j+1];
                    a[j+1]=w;
                }
            }
        }
        cout<<a[n-1];
    }
    if(m==n){
        int ans=a[0];
        for(int j=1;j<sizeof(a);j++){
            ans=(ans&a[j]);
        }
        cout<<ans;
    }
    if(m==2){
        for(int i=0;i<sizeof(a);i++){
            for(int j=0;j<sizeof(a);j++){
                ans2=(a[0]&a[1]);
                ans2=max(tong[i][j],ans2);
            }
        }
        cout<<ans2;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,x;
int a[200005];
int b[5005][5005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            b[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;a[i]!=0;j++){
            if(x<j)x=j;
            b[i][j]=a[i]%2;
            a[i]/=2;
        }
    }
    cout<<x;
    if(m==n){
        int y=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=n;j++){
                if(b[j][i]==0){
                    for(int k=1;k<=n;k++){
                        b[k][i]==0;
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=x;i++){
            ans+=b[1][i]*y;
            y*=2;
            cout<<ans<<endl;
        }
    }
    cout<<ans;
    return 0;
}

#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N];
bool f[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i]=1;
    }
    int ans=0;
    for(int k=30;k>=0;k--){
        int t=(1<<k),cnt=0;
        for(int j=1;j<=n;j++){
            if(f[j]&&(a[j]&t)) cnt++;
        }
        if(cnt>=m){
            ans+=t;
            for(int j=1;j<=n;j++){
                if(f[j]&&!(a[j]&t)) f[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int n,m,z=1,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=200010;i++){
        b[i]=i;
    }
    for(int i=m+1;i<=n;i++){
        z*=i;
    }
    for(int i=1;i<=n-m;i++){
        z/=i;
    }
    for(int i=1;i<=z;i++){
        int c=a[b[m]],x=m-1;
        while(x>0){
            c=c&a[b[x]];
            x--;
        }
        ans=max(ans,c);
        b[m]++;
        for(int j=m;j>=1;j--){
            int d=1;
            if(b[i]>n-d+1){
                b[i-1]++;
                b[i]=b[i-1]+1;
            }
            d++;
        }
        for(int j=1;j<=m;j++){
            if(b[j+1]-b[j]==2){
                b[j+1]--;
            }
        }
    }
    cout<<ans;
    return 0;
}

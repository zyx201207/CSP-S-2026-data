#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool ca[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ca[i]=1;
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(ca[j]){
                if(a[j]&(1<<i)){
                    cnt++;
                }
            }
        }
        if(cnt>=m){
            ans|=(1<<i);
            for(int j=1;j<=n;j++){
                if(ca[j]){
                    if(a[j]&(1<<i)){
                        ca[j]=1;
                    }
                    else{
                        ca[j]=0;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}//yellow for 0.3h
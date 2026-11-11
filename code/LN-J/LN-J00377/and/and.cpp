#include<bits/stdc++.h>
using namespace std;
int a[200005][50];
bool flag[200005];
void chai(int b,int p){
    int cnt=0;
    while(b){
        cnt++;
        int c=b%2;
        a[p][cnt]=c;
        b/=2;
    }
}
int suan(int x){
    int v=1;
    for(int i=2;i<=x;i++){
        v*=2;
    }
    return v;
}
int main(){
    int n,m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        chai(x,i);
    }
    int ans=0;
    for(int j=31;j>=1;j--){
        int cnt=0;
        for(int i=1;i<=200000;i++){
            if(a[i][j]==1&&flag[i]==0){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=suan(j);
            for(int i=1;i<=200000;i++){
                if(a[i][j]==0){
                    flag[i]=1;
                }
            }
        }
    }
    cout<<ans;

}

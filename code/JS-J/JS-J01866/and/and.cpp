#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        int s=1<<i;
        for(int j=1;j<=n;j++){
            if((a[j]&s)!=0){
                cnt++;
            }
        }
        if(cnt>=m){
            ans|=s;
            for(int j=1;j<=n;j++){
                if((a[j]&s)==0){
                    a[j]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
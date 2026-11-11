#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int r=1;r<=n;r++){
        int mm=m,cnt=0;
        for(int l=1;l<=r;l++){
            if(a[l]+mm>a[r]){
                mm-=a[l];
                cnt++;
            }
            else if(a[l]+mm==a[r]){
                cnt++;
                break;
            }
            else break;
        }
        maxn=max(cnt,maxn);
    }
    cout<<maxn;
    return 0;
}

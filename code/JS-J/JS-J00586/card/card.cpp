#include <bits/stdc++.h>
using namespace std;
int n,m,a[300005],c[300005],sta[300005],idx=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    cin >> n >> m;
    //
    bool flag=1,flag2=1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>=a[i-1]) flag=0;
        if(a[i]<=a[i-1]) flag2=0;
    }
    //
    if(flag){
        for(int i=n;i>=1;i--){
            cout << i << " ";
        }
        return 0;
    }
    if(flag2){
        for(int i=1;i<=n;i++){
            cout << i << " ";
        }
        return 0;
    }
    //
    for(int i=1;i<=n;i++){
        memset(sta,0,sizeof(sta));
        idx=0;
        for(int j=i;j<=n;j++){
            bool is=0;
            for(int k=idx;k>=1;k--){
                if(sta[k]==a[j]){
                    is=1;
                    int cnt=0;
                    for(int l=k;l<=idx-1;l++){
                        sta[l]=0;
                        cnt++;
                    }
                    idx-=cnt;
                    break;
                }
            }
            sta[++idx]=a[j];
        }
        //
        for(int j=1;j<=idx;j++){
            c[sta[j]]++;
        }
    }
    //
    for(int i=1;i<=m;i++){
        cout << c[i] << " ";
    }
    //
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int sel[30],seln=0,ans=0,m;
int a[30];
int cal(){
    int ans=sel[0];
    for(int i=1;i<m;i++){
        ans=(ans&sel[i]);
    }
    return ans;
}
void selec(int l,int r,int m){
    if(r-l<m){
        return;
    }
    for(int i=l;i<r;i++){
        sel[seln]=a[i];
        seln++;
        if(seln==::m){
            ans=max(ans,cal());
            seln--;
            return;
        }
        selec(i+1,r,m-1);
        seln--;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ma=0;
        for(int i=0;i<n;i++){
            ma=max(a[i],ma);
            cout<<ma;
        }
    }
    else if(m==n){
        int ma=a[0];
        for(int i=1;i<n;i++){
            ma=(ma&a[i]);
        }
        cout<<ma;
    }
    else if(m==2){
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ma=max(ma,(a[i]&a[j]));
            }
        }
        cout<<ma;
    }
    else{
        selec(0,n,m);
        cout<<ans;
    }
    return 0;
}

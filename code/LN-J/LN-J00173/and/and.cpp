#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxx;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        maxx=0;
        for(int i=1;i<=n;i++){
                maxx=max(maxx,a[i]);
        }
    }
    if(m==n){
        maxx=a[1];
        for(int i=2;i<=n;i++){
                maxx&=a[i];
        }
    }
    if(m==2){
        maxx=0;
        int no;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                no=a[i]&a[j];
                maxx=max(maxx,no);
            }
        }
    }
    cout<<maxx;
    return 0;
}

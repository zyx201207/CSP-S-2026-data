#include<bits/stdc++.h>
using namespace std;
struct ss{
    int x,y;
}a[2000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
        }
        int cnt=0;
        for(int i=3;i<n;i++){
            if(abs(a[i-2].x-a[i-1].x)==abs(a[i-1].x-a[i].x)
               &&abs(a[i-2].x-a[i-1].x)==abs(a[i+1].x-a[i].x)
               &&abs(a[i-2].x-a[i-1].x)!=abs(a[i-3].x-a[i-2].x)
               &&abs(a[i-2].x-a[i-1].x)!=abs(a[i+1].x-a[i+2].x)
               &&abs(a[i-2].x-a[i-1].x)<=m){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int kk=0;
    int f=0;
    cin>>kk>>f;
    for(int k=1;k<=f;k++){
        int n=0,m=0,a[2000005]={},x=0,y=2;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int x1=a[2]-a[1];
        while(x==0){
            if(a[y+1]-a[y]!=x1){
                x=1;
            }else{
                y++;
            }
            if(y==n){
                break;
            }
        }

        if(x==0){
            int y1=m/x1;
            cout<<n-y1-1;
        }
        cout<<0;
    }
    return 0;
}

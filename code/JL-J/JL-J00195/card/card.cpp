#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],q=0,w=0,g=0,h=0,qw=0,wq=0,l;
int b(int x,int y){
    while(x!=0){
        q=q+x%2*10;
        x=x/2;
        g++;
    }
    while(y!=0){
        w=w+y%2*10;
        y=y/2;
        h++;
    }
    if(g>=h){
        for(int i=g;i>=1;i++){
            if(q%10==w%10){
                qw=qw*10+1;
            }else{
                qw=qw*10;
            }
        }
    }else{
        for(int i=h;i>=1;i++){
            if(q%10==w%10){
                qw=qw*10+1;
            }else{
                qw=qw*10;
            }
        }
    }
    for(int i=0;i<=max(g,h)-1;i++){
        l=1;
        for(int j=1;j<=i;j++){
            l=l*2;
        }
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    return 0;
}

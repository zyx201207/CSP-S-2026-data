#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200020],x,y,tot,ansx=0,ansy=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // x=a[i];
        // if(a[i]!=x) y=a[i];
    }
    if(m==2){
        tot=a[n];
        for(int i=1;i<=n;i++){
            if(a[i]==tot) {
                if(a[i]==1) ansx+=1;
                else if(a[i]==2) ansy+=1;
            }else{
                ansx+=1;
                ansy+=1;
            }
        }
        cout<<ansx<<' '<<ansy;
    }
    else{
        int number=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=number){
                cout<<i-1<<' ';
                number=a[i];
            }
        }
    } //for(int i=1;i<=m;i++) cout<<'1'<<' ';
    return 0;
}
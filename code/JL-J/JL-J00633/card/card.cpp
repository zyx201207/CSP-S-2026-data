#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],b[N],cnt=0,c=1,t,g;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<n;j++){
            if(a[i]==a[j]){
               b[N]=0;
               b[1]=a[i];
            }else{
               b[++g]=a[i];
            }
        }for(int j=1;j<=g;j++){
            if(b[i]==c){
                t++;
            }
            if(t!=0){
                cnt++;
            }
        }
        cout<<cnt<<' ';
        c++;
        t=0;

    }
    return 0;
}

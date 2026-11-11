#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int m,n,i,j;
int t,ans,ans2[5],ad;
int a[N],c[N],anst[N];
bool b=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
        if(a[i]<a[i-1]){
            b=0;
        }
    }
    if(b){
        //A
        for(i=1;i<=m;i++){
            ad=ad+c[i];
            cout<<ad<<" ";
        }
        return 0;
    }
    if(m==2){
        ans2[1]=c[1];
        ans2[2]=c[2];
        ans2[a[n]]=n;
        cout<<ans2[1]<<" "<<ans2[2];
        return 0;
    }
    return 0;
}

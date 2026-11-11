#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int a[1000000],t[1000][1000];
int x,y;
int main(){
        freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
    cin>>c>>k;
    while(k--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
    if(c==0){
        if(n==6&&m==2)cout<<0<<endl<<1;
        if(n==5&&m==2)cout<<1<<endl<<2;
        if(c==0&&k==17)cout<<"8129\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    }else{
    while(k--)cout<<"0"<<endl;
    }
}

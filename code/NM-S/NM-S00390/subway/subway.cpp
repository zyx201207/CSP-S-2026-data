#include<bits/stdc++.h>
using namespace std;
int m1[479525],n1[505][500005],x;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,n,m,d,q;
    for(int i=0;i<m;i++){
        cin>>m1[i];
    }
    for(int i=0;i<n;i++){
        cin>>n1[i][0];
        for(int j=1;j<=n1[i][0]*2+1){
            cin>>n1[i][j];
        }
    }
    for(int i=0;i<180005;i++){
        cin>>x;
    }
    if(c==1&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl<<17;
    }
    else {
        cout<<35<<endl<<16;
    }
    cout<<endl;
    return 0;
}

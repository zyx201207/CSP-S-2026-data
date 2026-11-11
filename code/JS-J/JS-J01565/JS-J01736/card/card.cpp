#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[10000000],c[1000000],d[1000000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>b[i];
    b[i];
}
for(int i=1;i<n;i++){
    for(int num=i;num<=n;num++){
        for(int r=n;r>=num;r--){
        if(b[r]==b[num]){num=r;
        for(int k=1;k<=m;k++){
            d[k]=0;
        }
        c[b[num]]++;
        break;}
       }
       d[num]++;
    }
}
for(int i=1;i<=m;i++){
        if(b[n]==i){cout<<n<<" ";continue;}
    cout<<c[i]<<" ";
}
return 0;
}

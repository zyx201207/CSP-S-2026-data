#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
signed main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>m>>n;
int yu[n];
int a[n];
int cnt=0;
for(int i=1;i<=m;i++){
    cin>>yu[i];
}
int num = 0;
if(yu[1]==yu[2]){
    for(int i=1;i<=m;i++){
    cnt++;
    if(yu[i]!=yu[i+1] || i==m){
        a[yu[i]]=cnt;
        }
    }
    for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
}
}



return 0;
}


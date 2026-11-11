#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[100005],b[10005];
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];

}
int cnt[n];
if(m==1){

    for(int i=n;i>=1;i--){
        while(a[i]/2==0){
            cnt[i]=a[i]%2;
            a[i]/=2;

            for(int j=n;j>=1;j--){
                cnt[i]*=10^j;
            }
sort(cnt,cnt+1);
cout<<cnt[1];
        }
}   }
if(m==2){

    if(n==1){
        cout<<a[1];
}
if(n==3){
        cout<<a[3];
}

}return 0;
}

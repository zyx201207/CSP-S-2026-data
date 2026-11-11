#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],b[500010];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    //scanf("%d",&a[i]);
    cin>>a[i];
}
sort(a+1,a+n+1);
//for(int i=1;i<=n;i++){
//    cout<<a[i]<<endl;1
//}
for(int i=1;i<=n;i++){
    b[i]=b[i-1]+a[i];
}
int num=0,fr=1;
for(int i=1;i<=n;i++){
    num++;
    while(a[i]*num-(b[i]-b[fr-1])>m){
        fr++;
        num--;
    }
        ans=max(num,ans);
}
    cout<<ans;


return 0;
}

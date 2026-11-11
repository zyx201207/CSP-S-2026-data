#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,ma;
void dfs(int k,int s){
    if(k==m){
        if(s>ma){
            ma=s;
        }
        return ;
    }
    for(int i=k+1;i<=n;i++){
        dfs(k+1,s&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(m==1){
    sort(a+1,a+1+n);
    cout<<a[n];
}
else if(m==2){
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]&a[j]>ma){
                ma=a[i]&a[j];
            }
        }
    }
    cout<<ma;
}
else if(m==n){
    int s=a[1];
    for(int i=2;i<=n;i++){
        s&=a[i];
    }
    cout<<s;
}
else{
    dfs(0,a[1]);
cout<<ma;
}
return 0;
}

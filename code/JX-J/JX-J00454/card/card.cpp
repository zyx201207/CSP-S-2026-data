#include<iostream>
using namespace std;
int su[100],sum[100];
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m,a[100],y=1;
cin>>n>>m;
int n1=n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
while(n>=0){
    for(int i=y;i<=n1;i++){
        if(su[a[i]]==0){
            su[a[i]]+=1;
        }
        if(su[a[i]]==2){
            for(int j=1;j<i;j++){
                su[j]-=1;
            }
        }
    }
    for(int i=1;i<=n1;i++){
        if(su[i]==1){
            for(int i=1;i<=m;i++){
                if(a[su[i]]==i){
                    sum[i]+=1;
                }
            }
        }
    }
    n--;
    y++;
}
for(int i=1;i<=m;i++){
    cout<<sum[i];
}
return 0;
}

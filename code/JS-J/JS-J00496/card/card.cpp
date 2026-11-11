#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m=0,x=0,y,z;
int a[N],b[N],c[N]={0};
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                for(int k=1;k<=m;k++){
                    if(b[k]<j&&b[k]>b[a[j]])b[k]=0;
                }
            }
            b[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(b[j])c[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

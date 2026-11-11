#include<bits/stdc++.h>
using namespace std;
long long a[600000]={0},b[600000]={0},c[600000]={0},d[600000]={0},n,m;
void fun(){
    for(long long i=1;i<=m;i++){
        c[i]=0;
        d[i]=0;
    }
    for(long long i=1;i<=n;i++){
        if(c[a[i]]==1&&a[i]){
            int index=i;
            while(index--){
                if(a[index]==a[i]){
                    d[index]=1;
                    break;
                }else{
                    d[index]=1;
                    c[a[index]]=0;
                }
            }
        }else c[a[i]]=1;
    }
    for(long long i=1;i<=n;i++){
        if(d[i]==0){
            b[a[i]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        a[i-1]=0;
        fun();
    }
    for(long long i=1;i<=m;i++){
        cout<<b[m]<<" ";
    }
}

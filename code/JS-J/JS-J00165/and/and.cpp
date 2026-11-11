#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200010],big=-1,nbig=-1,b,sum,la;
queue<bool> b1;
queue<bool> b2;
bool b11[20010],b22[20010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>big){
            big=a[i];
            b=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(nbig<a[i] && i!=b){
            nbig=a[i];
        }
    }
    while(big>0){
        b1.push(big%2);
        big=big/2;
    }
    while(nbig>0){
        b2.push(nbig%2);
        nbig=nbig/2;
    }
    if(b1.size()>b2.size()){
        la=b1.size();
    }
    else{
        la=b2.size();
    }
    for(int i=b1.size();i>=1;i--){
        b11[i]=b1.front();
        b1.pop();
    }
    for(int i=b2.size();i>=1;i--){
        b22[i]=b2.front();
        b2.pop();
    }

    for(long long i=1;i<=la;i++){
        if(b11[i]==1 && b22[i]==1){
            long long cnt=1;
            for(int j=2;j<=i;j++){
                cnt*=2;
            }
            sum+=cnt;
        }
    }
    cout<<sum;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int sc[100003]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> pai;
        int tong[m+20]={};
        for(int j=i;j<=n;j++){
            int k=a[j];
            if(tong[k]==0){
                pai.push(k);
                tong[k]=1;
            }
            else{
               while(1){
                 if(pai.empty()==0 and pai.top()==k){
                    tong[pai.top()]=0;
                    pai.pop();
                    break;
                 }
                 else{
                    tong[pai.top()]=0;
                    pai.pop();
                 }
               }
               pai.push(k);
               tong[k]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(tong[j]==1){
                sc[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sc[i]<<' ';
    }
    return 0;
}


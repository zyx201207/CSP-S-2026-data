#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
int b[50005][30005];
int main(){
    init();
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[n];
    }
    for(int i=0;i<n;i++){
        int d[m]={0},e=0,l=0;
        for(int j=i;i<n;j++){
            if(d[a[i]]){
                e=i+1;
                l++;
            }else{
                d[a[i]]=1;
                l++;
            }
        }
        for(int j=e;j<n;j++){
            b[i][a[j]]=1;
        }
    }
    int c[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[b[i][j]]++;
        }
    }
    for(int i=0;i<m;i++){
        if(i){
            cout<<" ";
        }
        cout<<c[i];
    }
}

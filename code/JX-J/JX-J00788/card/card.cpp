#include<bits/stdc++.h>
using namespace std;
int n,m;
int cf(int fd,int a[],int st,int en){
    for(int i=st;i<=en;i++){
        if(a[i]==fd)return i;
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c[n]={};
    for(int i=0;i<n;i++){
        int f[m]={};
        int b[n]={};
        for(int x=i;x<n;x++){
            b[x]=a[x];
        }
        for(int j=i;j<n;j++){
            int t=cf(b[j],b,i,j);
            if(t!=-1){
                for(int k=j-1;k>=t;k--){
                    b[k]=0;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                if(b[k]==j+1&&f[j]==0){
                    c[j]++;
                    f[j]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++)cout<<c[i]<<' ';
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[100000],b[100000]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        int s[100000];
        while(a[i]>0){
        int y=a[i]%2;
        for(int j=0;j<1000;j++){
           s[j]=y;
        }
        a[i]=a[i]/2;
        }
        b[i]+=s[i];
    }
    for(int j=0;j<=n;j++){
        for(int i=j;i<=n;i+=m){
            b[i]=b[i]+b[i+1];
        }
    }
    sort(b[1],b[n]);
    cout<<b[n];
}


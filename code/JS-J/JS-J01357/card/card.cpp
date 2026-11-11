#include<bits/stdc++.h>
using namespace std;
int d[5000000];
int main(){
    int m,n;
    cin>>m>>n;int a[m]={},b[n]={};int c[m]={};
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int j=i;
       for(int i=0;i<m;i++){
      c[i]=a[i];
    }int cnt=0;
        while(1){int f=1;
        while(c[j]==0){j++;if(j>=m);f=0;break;}if(f==0)break;
        for(int k=0;k<cnt;k++){
            if(d[k]==c[j]){for(int e=k;e<cnt;e++)d[e]=0; }
        }
        d[cnt]=c[j];
        c[j]=0;cnt++;

        }for(int k=0;k<cnt;k++){
        b[d[k-1]]++;}
    }for(int i=0;i<n;i++){
    cout<<b[i];}
return 0;}

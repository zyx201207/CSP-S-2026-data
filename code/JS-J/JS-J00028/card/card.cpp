#include <bits/stdc++.h>
using namespace std;
int n,m;
int c[300000+10];
int a[500000+10];
int b[500000+10];
int main(){
    cin>>n;
    for(int p=0;p<n;p++){
        for(int i=p;i<n;i++){
            cin>>a[i];
        }
        for(int i=p;i<n;i++){
            b[i]=a[i];
            for(int j=p;j<i;j++){
                if(b[j]==b[i]){
                    for(int k=j+1;k<=i;k++){
                        b[k]=0;
                    }
                }
            }
        }
        for(int i=p;i<n;i++){
           if(b[i]!=0){
               c[b[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i];
    }
    return 0;
}
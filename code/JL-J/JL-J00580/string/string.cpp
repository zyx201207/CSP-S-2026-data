#include<bits/stdc++.h>
using namespace std;
int a[1000];
char b[1000],c[1000];
int main(){
    int n,R=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int m=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b[m]=c[i];
            m++;

        }
    }
    for(int i=0;i<=m/2;i++){
        if(b[i]!=b[m-i]){
            R++;
        }
    }
    cout<<R;
    return 0;
}

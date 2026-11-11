#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,kd;
    cin >> n >> m;
    long long a[n]={},b[m]={},c[n]={};
    for(int i=1;i<=n;i++){
        cin >> kd;
        a[i]=kd;
    }
    int l=0;
    for(int i=1;i<=n;i++){
        int b[m]={},l=0;
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            if(b[a[j]]>1){
                l=j;
            }
        }
        for(int j=l;j<=m;j++){
            c[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << c[i] << " ";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={};
    int b[n][100005]={};
    int c[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
            int j=0;
        while(a[i]>0){
            b[i][j]=a[i]%2;
            a[i]/=2;
            j+=1;
        }
        c[i]=j;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    fre("and.in","r",stdin);
    fre("and.out","w",stdout);
    long long n,m,a[1000000],b[n+1][1000000],o=0,p=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            o=0;
        while(a[i]>0){
            b[i][o]=a[i]%2;
            a[i]/=2;
            o+=1;
        }
    }
    for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){

    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


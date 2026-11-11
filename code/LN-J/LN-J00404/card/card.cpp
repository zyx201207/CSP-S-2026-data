#include<bits/stdc++.h>
using namespace std;
int pai[10000000];
int cp(int b[1000000],int d){
    for(int i=0;i<d;i++){
        for(int j=0;i<d&&i!=j;j++)
            if(d[i]==d[j]) {
                pai[i]--;
                pai[j]--;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    int a[m+5];
    for(int i=0;i<m;i++) cin>>a[i];
    for(int k=0;k<m;k++) pai[k]=m*n;
    cp(a,m);
}

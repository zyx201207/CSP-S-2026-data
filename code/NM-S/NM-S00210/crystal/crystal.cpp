#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a[100];
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=m;j++){
        a[j]+1;
        if(a[j]<a[j+1]){
            j--;
            m--;
        }
    if(a[j]<a[j+1]){
                a[j]++;
                m--;
            }
    if(a[j-1]<a[j]){
        a[j-1]++;
        m--;
    }

    }
    for(int x=1;x<=n;x++){
        if(a[1]==a[x+1]){
            sum++;
        }
    }
    cout<<sum;



}

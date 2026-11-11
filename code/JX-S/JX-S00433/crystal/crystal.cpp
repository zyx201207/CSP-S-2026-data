#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int a[N];
int n,m;
int main(){
    cin>>n>>m;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(a[i]==4){
           a[i]=m;
           m++;
        }
    }
    cout<<m-3;
    return 0;
}

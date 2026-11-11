#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int min;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    min=a[1];
    for(int i=1;i<=m;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    cout<<min;
    return 0;
}

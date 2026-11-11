#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200000];
int find(int x){
    long long sum=0;
    for(int i=x;i>=0;i--){
        if(a[x]-a[i]<=n){
            sum+=find(a[i]);
        }
    }
    if(x==0){
        return 0;
    }
    else if(x==1||x==2){
        return 1;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int x[t];
    for(int i=0;i<t;i++){
        cin>>m>>n;
        for(int j=0;j<m;j++){
            cin>>a[j];
            cout<<find(a[j]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

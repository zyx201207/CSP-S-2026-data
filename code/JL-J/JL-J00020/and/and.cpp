# include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int er(int x){
    int cnt=0,bu=0,b[200005]={};
    while(x>0){
        b[bu]=x/2;
        x=x%2;
        bu++;
    }
    for(int i=bu;i>=0;i--){
        cnt=cnt*10+b[i];
    }
    return cnt;
}
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}

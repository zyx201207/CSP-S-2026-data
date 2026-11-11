#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

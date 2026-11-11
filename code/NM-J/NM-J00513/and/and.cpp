#include<bits/stdc++.h>
using namespace std;
bool cmp(int q,int h){
    return q>h;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);
    int t=a[1];
    for(int i=2;i<=m;i++){
        t&=a[i];

    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);



return 0;
}

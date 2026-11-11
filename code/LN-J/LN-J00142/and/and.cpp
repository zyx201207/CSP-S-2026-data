#include<bits/stdc++.h>
using namespace std;
long long a[200001],andsum;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    andsum=a[0];
    for(int i=1;i<m;i++){
        andsum=andsum&a[i];
    }
    cout<<andsum;
    return 0;
}

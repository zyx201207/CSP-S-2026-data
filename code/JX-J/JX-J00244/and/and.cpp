#include<bits/stdc++.h>
using namespace std;
long long num,a[100000005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=m;i++){
        if(i==2)num=a[i]&a[i-1];
        else num=a[i]&num;
    }
    cout<<num;
}

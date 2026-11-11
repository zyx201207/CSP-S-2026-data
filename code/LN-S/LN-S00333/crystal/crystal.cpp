#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long q[500010];
bool cmp(long long a,long long b){
    return a < b;
}
void two(int l,int r){
    int mid = (l+r)/2;
    if(l>=r-1){
        if((q[mid]+m)/mid <= a[mid])
            cout << l;
        else
            cout << r;
        return;
    }
    if((q[mid]+m)/mid < a[mid]){
        two(l,mid);
    }else{
        two(mid,r);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i <= n;i++){
        q[i] = q[i]+a[i];
    }
    two(1,n+1);
    return 0;
}

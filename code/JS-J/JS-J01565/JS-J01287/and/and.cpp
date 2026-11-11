#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(m==1){
        sort(a,a+n,cmp);
        cout << a[0];
    }
    sort(a,a+n,cmp);
    cout << a[n/2];
    return 0;
}

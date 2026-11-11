#include<bits/stdc++.h>
using namespace std;
int k,a[100005],q;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> k >> q;
    for(int i = 0;i < k;i++){
        cin >> a[i];
    }
    sort(a,a+k,cmp);
    long long ans=a[0];
    for(int i = 1;i < q;i++){
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}
//(暴力)
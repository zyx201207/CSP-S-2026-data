#include<bits/stdc++.h>
using namespace std;
unsigned long long x[200005];
unsigned long long ans;
int m,n;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    sort(x, x+n);
    ans = x[n-1];
    for(int i=n-2;i>n-2-m;i--){
        ans &= x[i];
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
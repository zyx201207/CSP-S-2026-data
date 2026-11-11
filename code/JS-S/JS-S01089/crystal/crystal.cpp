#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[50005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cnt =0;
    for(int i=2;i<=n;i++){
        cnt +=(i-1)*(a[i]-a[i-1]);
        if(cnt>m){
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout << n <<endl;
    return 0;
}

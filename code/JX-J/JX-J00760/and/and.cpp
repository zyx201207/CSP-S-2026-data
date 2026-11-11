#include <iostream>
using namespace std;
string sl(int a){
    string s;
    while(a>0){
        s+=a%2;
        a/2;
    }
    return s;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],maxn=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    if(m=1){
        cout << maxn;
        return 0;
    }
    cout<<a[n];
    return 0;
}

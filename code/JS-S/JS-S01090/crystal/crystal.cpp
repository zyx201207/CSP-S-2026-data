#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[50005];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long res=0;
    for(int i=2;i<=n;i++){
        res+=(i-1)*(a[i]-a[i-1]);
        if(res>m){
            cout<<i-1<<endl;
            return 0;
        }

    }
    cout<<n<<endl;
    return 0;
}


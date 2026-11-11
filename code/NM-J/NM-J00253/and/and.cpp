#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010]={0};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n>>m;
    for(int i = 1 ; i <= n ;i++){
        cin >> a[i];
    }
    long long t=0;
    for(int i = 1 ; i <= n;i++){
        for(int j = 1 ;j <= n ;j++){
            if(a[i]&a[j]>t)t=a[i]&a[j];
        }

    }
    for(int i = 1 ; i <= n;i++){
            if(a[i]&t>t)t=a[i]&t;
        }

    cout<<a[n];
    return 0;
}

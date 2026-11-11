#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    long long a[MAXN];
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int ans = a[0] % a[1];

    cout<<ans;
}

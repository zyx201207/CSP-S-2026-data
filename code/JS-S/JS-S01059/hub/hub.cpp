#include<bits/stdc++.h>
using namespace std;

int c,t;
struct stu{
    int w,u;
}a[2000005];

int main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin >> c >> t;
    for(int i=1;i<=t;i++){
        int n,k;
        for(int j=1;j<n;j++){
            cin >> a[i].w >> a[i].u;
        }
    }

    return 0;
}

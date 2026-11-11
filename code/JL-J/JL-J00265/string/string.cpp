#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","s",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long x,cnt=0;
    char y,a;

    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(i==1) a=y;

        for(int j=1;j<=x;j++){
            if(y!=a) cnt++;
        }

    }

    cout<<cnt;
    return 0;
}

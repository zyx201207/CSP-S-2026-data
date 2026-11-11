#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,s;
    cin>>a>>s;
    long long d[1000000];
    int f[100][100],z=0;

    for(int i=1;i<=a;i++){
        cin>>d[i];
    }
    sort(d,d+a,greater<int>());
    for(int i=1;i<=1;i++){
        cout<<d[i];
    }
    return 0;
}

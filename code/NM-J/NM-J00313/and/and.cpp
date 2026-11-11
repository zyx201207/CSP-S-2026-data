#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long c[1000005],d;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    sort(c-1,c+a+1);
    cout<<c[a-b+1];
    return 0;

}

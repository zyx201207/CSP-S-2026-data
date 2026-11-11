#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("end.in","r",stdin);
    freopen("end.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long d[100000];
    for (int i=0;i<a;i++){
        cin>>d[i];
    }
    sort(d,d+a);
    cout<<d[a-b];
    return 0;
}

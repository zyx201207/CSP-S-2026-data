#include<bits/stdc++.h>
using namespace std;
int a[500010][3];
int main(){
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
    long long c,n;
    cin >>c >>n;
    for(int i=1;i<=n;i++){
            int x1,x2;
    cin >>x1>>x2;
      cout << abs(x1-x2)<<endl;
    }
    return 0;
}

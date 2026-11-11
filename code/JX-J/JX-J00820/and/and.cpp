#include <bits/stdc++.h>
using namespace std;
long long n,m,h[200005],p,a[200005];
int main(){
        freopen("and.in","r",stdin);                                         
                                                                                
        freopen("and.out","w",stdout);                                       
                                                                                
        cin >> n >> m;
        for (long long i = 1;i <= n;i++){
                cin >> a[i];
                h[1]=max(h[1],a[i]);
        }
        for (long long i = 1;i <= n;i++){
                for (long long j = 1;j <= m;j++){
                        h[j]=max(h[i],max(h[j-1]&a[i],a[i]));
                }
        }
        cout << h[m];
        return 0;
}




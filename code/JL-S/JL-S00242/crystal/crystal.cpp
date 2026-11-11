#include<bits/stdc++.h>
using namespace std;

long long a[1000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long k=0;
long long u=0;
    for(long long i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
long long ans=1;

    for(long long i=0;i<n;i++){
        //    cout << "a[i]     "  << a[i] << endl;
            if(m>=(a[i+1]-a[i])*(u+1)){
                    u++;
                m=m-(a[i+1]-a[i])*u;
                ans++;
            }
            else break;

    }
 //   cout << m << endl;
  //  cout << d << ' ' << s << endl;
    cout << ans;


    return 0;
}

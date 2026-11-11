#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    cin.tie();
    ll n,m,mx=0;
    int k=0;
    cin>>n>>m;
    vector <ll> l(n);
    vector <ll> s(m+1);
    for (int i=0 ; i<n ; i++){
            cin>>l[i];
        for (int j=1 ; j<n ;j++){
            if (l[i] >= l[j] and l[j] !=0) {
                    s[k]=l[j];
                    if (k!=m)k++;
                    else s[1]==l[j];
            }
            sort(s.begin(),s.end());
        }
    }
    cout<<s[m];
    return 0;
    }

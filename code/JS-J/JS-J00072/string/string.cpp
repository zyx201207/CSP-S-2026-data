#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], frank_fcc;
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> c[i];
        frank_fcc+=a[i];
    }
    long long p=1, q=n, s=0, t=frank_fcc, ans=0, k=0;
    while(q!=p){
        if(s+a[p]+t-a[q]-frank_fcc<0){
            if(c[p]!=c[q]){
                ans+=s+a[p]-k;
            }
            s+=a[p];
            p++;
            k=s;
        }else{
            if(c[p]!=c[q]){
                ans+=frank_fcc-t+a[q]-k;
            }
            t-=a[q];
            q--;
            k=frank_fcc-t;
        }
    }
    cout << ans;
    return 0;
}
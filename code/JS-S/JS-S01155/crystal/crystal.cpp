#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long i,l=1,ma=0;
    for(i=1;i<n;i++){
        while(m<(a[i+1]-a[i])*(i-l+1)){
            ma=max(i-l+1,ma);
            m+=a[i]-a[l];
            l++;
        }
        m-=(a[i+1]-a[i])*(i-l+1);
    }
    ma=max(i-l+1,ma);
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,s,max_=0;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=0;i<n+1-m;i++){
        s=a[i];
        for(long long j=i+1;j<i+m;j++){
            s&=a[j];
        }
        max_=max(max_,s);
    }
    cout<<max_;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

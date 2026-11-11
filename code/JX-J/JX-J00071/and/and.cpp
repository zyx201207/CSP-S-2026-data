#include<bits/stdc++.h>
using namespace std;
long long n,m,MAXN=0;
long long a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(MAXN<a[i]){
                MAXN=a[i];
            }
        }
        cout<<MAXN<<"\n";
        return 0;
    } else  if(m==n) {
        cin>>a[1];
        MAXN=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            long long g=MAXN;
            MAXN=g&a[i];
        }
        cout<<MAXN<<"\n";
        return 0;
    }
    sort(a,a+n);
    for(int i=n;i>=n-m;i--){
        long long g=MAXN;
        MAXN=g&a[i];
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    cout<<MAXN<<"\n";
    return 0;
}

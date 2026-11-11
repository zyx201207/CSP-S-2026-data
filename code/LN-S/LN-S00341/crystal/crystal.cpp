#include <bits/stdc++.h>
using namespace std;

const int N=500010;
int n;
int ans,len,fr=1,re=1;
long long m,a[N],last;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    last=a[1];
    len=1;
    for(int i=2;i<=n;i++){
        re++;
        len++;
        long long cost=(len-1)*(a[re]-last);
        while(cost>m){
            m+=last-a[fr];
            fr++;
            len--;
            cost=(len-1)*(a[re]-last);
        }
        m-=cost;
        ans=max(ans,len);
        last=a[re];
    }
    cout<<ans;
    return 0;
}

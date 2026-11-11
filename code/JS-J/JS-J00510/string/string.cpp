#include<bits/stdc++.h>
using namespace std;
struct s{
    int l,ll;
    char c;
};
s a[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        a[i].ll=m+1;
        m+=a[i].l;
    }
    int l=1,r=m,ll=1,rr=n;

    long long s=0;
    while(l<r){
        char lc=a[ll].c,rc=a[rr].c;
        if(lc!=rc)s++;
        l++;
        r--;
        if(l==a[ll+1].ll){
            ll++;
        }
        if(r==a[rr].ll-1){
            rr--;
        }
        if(l==r)break;
    }
    cout<<s;
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1010110],l[1010110],r[101110];
char c[1010110];
int ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l[i]=r[i-1]+1;
        r[i]=l[i]-1+a[i];
    }
    int i=0,j=n+1,ll=0,rr=0;
    while(i+1<j){
            int pl=ll,pr=rr;
        if(ll<=rr&&i+1!=j){
            i++;
            ll+=a[i];
        }if(ll>=rr&&i+1!=j){
            j--;
            rr+=a[j];
        }
        if(c[i]!=c[j]){
            ans+=min(ll,rr)-min(pl,pr);
        }//cout<<i<<" "<<j<<" "<<ans<<" "<<ll<<" "<<rr<<" "<<endl;
    }
    cout<<ans;
    return 0;
}/*
5
5
7 a
4 b
5 c
2 b
6 a









inclusteam
dcciyiyz
tdchuidiervsxt
2026/10/31 8:30:00
*/

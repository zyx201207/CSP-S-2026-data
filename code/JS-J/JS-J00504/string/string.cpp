#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,len=1,a[N],ans;
int l1[N],r1[N],l2[N],r2[N];
char c,c1[N],c2[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        c1[i]=c;
        l1[i]=len;
        r1[i]=len+a[i]-1;
        len+=a[i];
    }
    int m=1;
    for(int i=1;i<=n;i++){
        c2[i]=c1[n-i+1];
        l2[i]=m;
        r2[i]=m+a[n-i+1]-1;
        m+=a[n-i+1];
    }
    m/=2;
    int i1=1,i2=1;
    while(l1[i1]<=m&&l2[i2]<=m){
       /* if(l1[i1]>r2[i2]) i2++;
        else if(l2[i2]>r1[i1]) i1++;*/
        if(c1[i1]!=c2[i2]){
            ans+=(min({r1[i1],r2[i2],m})-max(l1[i1],l2[i2])+1);
        }
        if(r1[i1]<r2[i2]) i1++;
        else if(r1[i1]>r2[i2]) i2++;
        else i1++,i2++;
    }
    cout<<ans;
    return 0;
}

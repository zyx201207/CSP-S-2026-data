#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,len;
int a[N],ans;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int l=1,r=len;
    int li=1,ri=n;
    while(l<=r){
        if(li==ri){
            break;
        }
        if(a[li]>a[ri]){
            l+=a[ri];
            r-=a[ri];
            a[li]-=a[ri];
            if(c[li]!=c[ri])ans+=a[ri];
            //cout<<l<<' '<<r<<"flag1"<<'\n';
            ri--;
        }
        if(a[li]<a[ri]){
            l+=a[li];
            r-=a[li];
            a[ri]-=a[li];
            if(c[li]!=c[ri])ans+=a[li];
            //cout<<l<<' '<<r<<"flag2"<<'\n';
            li++;
        }
        if(a[li]==a[ri]){
            if(c[li]!=c[ri])ans+=a[li];
            l+=a[li];
            r-=a[ri];
            a[li]=a[ri]=0;
            li++;
            ri--;
            //cout<<l<<' '<<r<<"flag3"<<'\n';
        }
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
pair<int,char> t[N],a[N];
int n,idx,l,r,cntl,cntr,res,sum;
void init(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
signed main(){
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].first;
    }
    int cnt=0,mid=(sum+1)>>1;
    for(int i=1;i<=n;i++){
        cnt+=a[i].first;
        if(sum%2){
            if(cnt>=mid){
                l=r=i,cntr=cnt-mid,cntl=a[i].first-cntr-1;
                break;
            }
        }
        else{
            if(cnt>=mid){
                l=r=i,cntr=cnt-mid,cntl=a[i].first-cntr;
                break;
            }
        }
    }
    while(l&&r<=n){
        if(cntl==cntr){
            if(a[l].second!=a[r].second) res+=cntl;
            l--,r++,cntl=a[l].first,cntr=a[r].first;
        }
        else if(cntl<cntr){
            if(a[l].second!=a[r].second) res+=cntl;
            cntr-=cntl,l--,cntl=a[l].first;
        }
        else{
            if(a[l].second!=a[r].second) res+=cntr;
            cntl-=cntr,r++,cntr=a[r].first;
        }
    }
    cout<<res<<"\n";
    return 0;
}

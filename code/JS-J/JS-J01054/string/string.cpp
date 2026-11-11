#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005],sum,pta[20005],al[200005],ar[200005],k;
bool vis[100005];
int n,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int len=n;
    for(int i=1;i<=len;i++){
        char c;
        cin>>a[i]>>c;
        sum+=a[i];
        b[i]=c-'a'+1;
        if(b[i]==b[i-1]){
            a[i-1]+=a[i];
            len--;
            i--;
        }
        pta[i]=pta[i-1]+a[i];
    }
    int mid=(sum+1)/2;
    ll lar=0,lal=0;
    for(int i=1;i<len;i++){
        if(pta[i]>mid){
            lar++;
            ar[lar]=sum-pta[i];
        }
        else {
            lal++;
            al[lal]=pta[i]-pta[i-1];
        }
    }
    sort(ar+1,ar+1+lar);
    int lft=0,rgt=0;
    for(int i=1;i<=max(lar,lal);i++){
        lft++;
        rgt++;
        if(al[lft]<=ar[rgt]&&b[lft]!=b[n-rgt+1]){
            ans+=min(al[lft],ar[rgt]);
        }
        else{
            ans+=max(al[lft],ar[rgt]);
        }
    }
    cout<<ans;
    return 0;
}

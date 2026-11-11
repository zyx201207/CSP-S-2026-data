#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],sum[N];
char c[N];
struct node{
    int x;
    char ch;
}b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int len=0;
    for (int i=1;i<=n;i++) len+=a[i];
    if (len<=2e8){
        int ans=0;
        vector<char> vec;
        vec.push_back('@');
        int mid=(len+1)/2;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=a[i];j++) vec.push_back(c[i]);
        }
        int l=0,r=0;
        if (len&1) l=mid-1,r=mid+1;
        else l=mid,r=mid+1;
        while (l>=1 && r<=len){
            if (vec[l]!=vec[r]) ans++;
            l--,r++;
        }
        cout<<ans;
    }
    /*
    int mid=(len+1)/2;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    if  (len&1){
        int ans1=0,id=0,idx=0,ans2=0;
        for (int i=1;i<=n;i++){
            if (sum[i]>=mid){
                id=i;
                break;
            }
        }
        for (int i=1;i<=n;i++){
            if (i==id){
                if (a[i]-sum[i]+mid-1!=0){
                    b[++idx].x=a[i]-sum[i]+mid-1;
                    b[idx].ch=c[i];
                }
                b[++idx].x=1;
                b[idx].ch=c[i];
                if (sum[i]-mid!=0){
                    b[++idx].x=sum[i]-mid;
                    b[idx].ch=c[i];
                }
            }
            else{
                b[++idx].x=a[i];
                b[idx].ch=c[i];
            }
        }
        int cur=0;
        int M=0;
        for (int i=1;i<=idx;i++){
            cur+=b[i].x;
            if (cur==mid){
                M=i;
                break;
            }
        }

        //for (int i=1;i<=idx;i++) cerr<<b[i].x<<" "<<b[i].ch<<'\n';
        int l=M-1,r=M+1;
        */
        /*
        int nowr=0,nowl=b[l].x,lst=0;
        //cerr<<r<<'\n';
        for (int i=r;i<=idx;i++){
            nowr+=b[i].x;
            if (nowr<=nowl){
                if (b[i].ch!=b[l].ch) ans1+=b[i].x;
                continue;
            }
            while (nowr>nowl){
                if (b[i].ch!=b[l].ch) ans1+=b[l].x-lst;
                l--,nowl+=b[l].x;
                lst=0;
            }
            if (b[l].ch!=b[i].ch){
                ans1+=(b[l].x-nowl+nowr);
                lst=b[l].x-nowl+nowr;
            }
            //cerr<<"ans1="<<ans1<<'\n';
            */
            /*
            int nowl=0,nowr=0,lstl=0,lstr=0;
            while (l>=1 && r<=idx){
                if (l!=lstl) nowl+=b[l].x,lstl=l;
                if (r!=lstr) nowr+=b[r].x,lstr=r;
                nowl+=b[l].x,nowr+=b[r].x;
                if (nowl==nowr){
                    if (b[l].ch!=b[r].ch) ans+=min(b[l].x,b[r].x);
                }
                if (nowl>nowr){
                    if (b[l].ch!=b[r].ch) ans+=
                }
            }
        }
        cout<<ans1;
    }
    */
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T=1;
    while (T--) solve();
    return 0;
}
/*
aabbaaaaabb
*/

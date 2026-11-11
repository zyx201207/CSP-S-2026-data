/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,minn;
int a[N];
bool check(int mid){
    minn=1e13;
    for(int i=mid;i<=n;i++){
        int cnt=1,sum=0;
        while(cnt<mid){
            sum+=a[i]-a[i-cnt];
            cnt++;
            //cout<<sum<<" "<<i<<" ";
        }

        minn=min(minn,sum);
    }
    //cout<<minn<<endl;
    return minn<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=0,r=n,res=0;
    while(l<=r){
        int mid=((l+r)>>1);
        if(check(mid)){
            l=mid+1;
            res=mid;
        }else r=mid-1;
    }
    cout<<res;
    return 0;
}
*/
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,minn;
int a[N],s[N],d[N];
bool check(int mid){
    minn=1e18;
    int l=0,r=0,sum=0;
    for(int i=mid;i<=n;i++){
        int x=s[i]-s[i-mid];
        if(x<minn){
            minn=x;
            r=i;
            l=i-mid+1;
        }
    }
    for(int i=r-1;i>=l;i--) sum+=a[r]-a[i];
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+d[i];
    int l=1,r=n,res=0;
    while(l<=r){
        int mid=((l+r)>>1);
        if(check(mid)){
            l=mid+1;
            res=mid;
        }else r=mid-1;
        //cout<<mid<<" ";
    }
    cout<<res;
    return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7


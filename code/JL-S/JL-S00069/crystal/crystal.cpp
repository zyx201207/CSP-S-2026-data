#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int n,a[N],num[N],sum[N],m;
bool cmp(int a,int b){
    return a<b;
}
bool check(int mid){
    int cnt=0;
    for(int i=1;i<mid;i++){
        cnt+=(a[mid]-a[i]);
    }
    return cnt<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int l=1,r=n,res=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            res=mid;
        }
        else{
            r=mid-1;
        }
    }

    cout<<res<<endl;
    return 0;
}
/*
int cnt=0;
    for(int i=1;i<res;i++){
        cnt+=a[res]-a[i];
    }
    cout<<cnt<<endl;
    if(cnt<m){
        res+=(m-cnt)/res;
    }
*/

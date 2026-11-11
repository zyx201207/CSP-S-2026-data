#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e5+10;

int n,m;
int a[N];
int ca[N];

bool check(int x){
    int p=a[x];
    unsigned long long sum=0;
    for(int i=1;i<=x;i++){
        sum+=p-a[i];
        if(sum>m)return false;
    }
    if(sum<=m)return true;
    else return false;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)==true){
            res=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+10;
const int MAXN=1e17;

int z[N];
int n;
int cnt=1;

bool check(int mid,int m){
    int res=0;
    for(int i=n;i>0;i--){
        if(z[i]>mid){
            continue;
        }
        else if(z[i] == mid){
            res++;
        }
        else if(mid-z[i]<=m){
            res++;
            m = m - (mid-z[i]);
        }
        else if(mid - z[i] > m){
            return 0;
        }

        cnt = max(cnt,res);

    }
    return 1;
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    int m;
    cin >> n >> m;
    int minn=MAXN;
    for(int i=1;i<=n;i++){
        cin >> z[i];
        minn=min(minn,z[i]);
    }

    sort(z+1,z+1+n);

    int l=minn,r=MAXN;
    while(l <= r){
        int mid = (r-l)/2 + l;
        if(check(mid,m)){

            l = mid + 1;

        }else{

            r = mid - 1;

        }
    }

    cout << cnt;

    return 0;
}

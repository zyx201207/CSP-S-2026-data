#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[500005];
int sum[35];

vector<int> xxx;

bool cmp(int x,int y){
    for(int i=0;i<xxx.size();i++){
        if( ((x>>xxx[i])&1) == ((y>>xxx[i])&1) )continue;
        return ((x>>xxx[i])&1) >= ((y>>xxx[i])&1);
    }
    return true;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long x=a[i];
        int j=0;
        while(x){
            if(x&1)sum[j]++;
            x>>=1;
            j++;
        }
    }

    int p;
    for(p=30;p>=0;p--){
       if(sum[p]>=m){
            xxx.push_back(p);
       }
    }
    sort(a+1,a+n+1,cmp);

    long long ans=(1<<30)-1;
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}

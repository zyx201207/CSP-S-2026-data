#include<bits/stdc++.h>
using namespace std;
struct STR{
    int num;
    char wt;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    struct STR a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].wt;
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r){
        if(a[l].wt==a[r].wt){
            int minn=min(a[l].num,a[r].num);
            a[l].num-=minn;
            a[r].num-=minn;
            if(a[l].num==0)l++;
            if(a[r].num==0)r--;
        }
        if(a[l].wt!=a[r].wt){
            int minn=min(a[l].num,a[r].num);
            ans+=minn;
            a[l].num-=minn;
            a[r].num-=minn;
            if(a[l].num==0)l++;
            if(a[r].num==0)r--;
        }
    }
    cout<<ans;
    return 0;
}
//Trick||Treat!

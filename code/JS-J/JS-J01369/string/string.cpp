#include<bits/stdc++.h>
using namespace std;
struct rg{
    int num;
    char chr;
}a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].chr;
    }
    long long ans=0;
    for(int i=1,j=n;i<j;){
        if(a[i].chr==a[j].chr){
            int minn=min(a[i].num,a[j].num);
            a[i].num-=minn;
            a[j].num-=minn;
            if(a[i].num==0)i++;
            if(a[j].num==0)j--;
        }
        else{
            int minn=min(a[i].num,a[j].num);
            ans+=minn;
            a[i].num-=minn;
            a[j].num-=minn;
            if(a[i].num==0)i++;
            if(a[j].num==0)j--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
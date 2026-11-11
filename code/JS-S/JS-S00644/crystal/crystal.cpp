#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],ans=0;
unsigned long long m;
bool spycheck=1;
long long gc;
//int lowbit(int x){
//    return x&(-x);
//}
//void add(int id,int k){
//    for(int x=id;x<=n;x+=lowbit(x))a[x]+=k;
//    return ;
//}
//int query(int x){
//    int res=0;
//    for(;x>=1;x-=lowbit(x))res+=a[x];
//    return res;
//}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        a[i]=x;

    }
    sort(a+1,a+1+n);
    gc=a[2]-a[1];
    for(int i=3;i<=n;i++){

        if(a[i]-a[i-1]!=gc){
            spycheck=0;
            break;
        }

    }
    if(spycheck){
        cout<<m/gc+1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long u=a[i],cnt=0;
        unsigned long long left=m;
        for(int j=i;j>=1;j--){
            long long v=a[j];
            if(u-v<=left){
                cnt++;
                left-=(u-v);
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

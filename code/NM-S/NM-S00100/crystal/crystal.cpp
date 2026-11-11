#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N];
bool check(int times,int goal){
    int g=upper_bound(a,a+n,goal)-a-1;
    if(g+1<times) return 0;
    int lastt=m;
    int kk=0;
    for(int i=g;i>=0;i--){
        lastt-=(goal-a[i]);
        if(lastt>=0){
            kk++;
            //cout<<lastt<<" "<<kk<<" "<<times<<" "<<(kk>=times)<<endl;
            if(kk>=times) return 1;
        }
        else return 0;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k,maxt=0,ll=0,rr=a[n-1]+1,midd;//cin>>k;
    for (int i=0;i<n;i++)
    {
        //k=a[(ll+rr)>>1];
        k=a[i];
        int l=0,r=n,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid,k)) l=mid+1;//m times can to mid*k?
            else r=mid;
        };
        if(r-1>maxt) maxt=r-1;
        /*if(maxt>rr){
            ll=k+1;
        }
        else{
            rr=k;
        }*/
    //if(r<=0) cout<<0<<" ";
    //else cout<<r-1<<" ";

    }
    //cout<<check(4,4);
    cout<<maxt;
    return 0;
}

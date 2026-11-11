#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
const int INF=1e12;
int n,opt,oopt,sta;
int test=6;
int a[MAXN];
int fu[MAXN],zheng[MAXN],idx;
bool A=1;
priority_queue<int> pq;
int lower(int sta){
    int l=1,r=n;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(sta>a[mid])l=mid+1,ans=mid;
        else r=mid-1;
    }
    return ans+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>opt;
    oopt=opt;
    int mi=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(a[i],mi);
    }
    int d=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=d)A=0;
    }
    if(A==1){
        int Ans=0;
        for(int i=1;i<=n;i++){
            if(opt<=0)break;
            opt-=i*d;
            Ans++;
        }
        cout<<min(Ans,n);
    }
    else{
       for(int i=1;i<=n;i++){
        if(mi<0){
            a[i]-=mi-1;
        }
        zheng[a[i]]++;
        if(zheng[a[i]]==1){
            pq.push(a[i]);
        }
    }
    sort(a+1,a+1+n);
    int ans=0;
    int rsult=-1;
    while(!pq.empty()){
        opt=oopt;
        ans=0;
        sta=pq.top();
        pq.pop();
        ans=zheng[sta];
        int f=lower(sta)-1;

        while(f>=1){
            int num=zheng[a[f]];
            int need=sta-a[f];

            if(need*num<=opt){
                ans+=num;
                opt-=need*num;
            }
            else{
                ans+=opt/need;
                break;
            }
            f=lower(f)-1;
        }

        if(ans>rsult){
            idx=sta;
        }
        rsult=max(rsult,ans);
    }
    cout<<rsult<<endl;
    }

    return 0;
}


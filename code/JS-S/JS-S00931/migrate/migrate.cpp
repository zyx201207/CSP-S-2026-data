#include<bits/stdc++.h>
using namespace std;
using lol=long long;
const int N=2000005;
lol d,x[N],ans,vr[N],vl[N];
int n,tr[N],tl[N];
int ll[N],lr[N],rl[N],rr[N];

int gtl(int l,int r,int x){
    // [l,r] how many p s.t. tl[p]=x
    return max(0, min(r,lr[x])-max(l,ll[x])+1);
}

int gtr(int l,int r,int x){
    return max(0, min(r,rr[x])-max(l,rl[x])+1);
}

void sol(int l,int r){
    // for(int i=l;i<=r;i++){
    //     for(int j=i+1;j<=r;j++){
    //         vector<int>A,B;
    //         int x=i;A.push_back(x);while(x<j)x=min(j,tr[x]),A.push_back(x);
    //         x=j;B.push_back(x);while(x>i)x=max(i,tl[x]),B.push_back(x);
    //         reverse(B.begin(),B.end());
    //         assert(A.size()==B.size());
    //         int sum=0;
    //         for(int p=0;p<A.size();p++){
    //             sum+=A[p]-B[p];
    //         }
    //         ans+=sum==1;
    //     }
    // }
    for(int i=l;i<r;i++){
        //start from i,i+1
        // cerr<<"start "<<i<<" "<<i+1<<endl;
        lol cl=0,cr=0;
        
        int j=i+1;
        cr=gtl(j+1,tr[j],i);
        if(tl[tr[j]]==i){
            j=tr[j];
            cr+=vr[j];
            // for(;;){
            //     cr+=gtl(j+1,tr[j],j);
            //     if(tl[tr[j]]!=j)break;
            //     j=tr[j];
            // }
        }

        j=i;
        cl+=gtr(tl[j],j-1,i+1);
        if(tr[tl[j]]==i+1){
            j=tl[j];
            cl+=vl[j];
            // for(;;){
            //     cl+=gtr(tl[j],j-1,j);
            //     if(tr[tl[j]]!=j)break;
            //     j=tl[j];
            // }
        }

        ans+=(lol)cl*cr;
    }
}
void solve(){
    ans=0;
    for(int i=1;i<=n;i++)ll[i]=lr[i]=rl[i]=rr[i]=vl[i]=vr[i]=0;
    cin>>n>>d;for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1,j=1;i<=n;i++){
        j=max(j,i);
        while(j<n&&x[j+1]-x[i]<=d)j++;
        tr[i]=j;
        if(!rl[j])rl[j]=i;
        rr[j]=i;
    }
    for(int i=n,j=n;i>=1;i--){
        j=min(j,i);
        while(j>1&&x[i]-x[j-1]<=d)j--;
        tl[i]=j;
        if(!lr[j])lr[j]=i;
        ll[j]=i;
    }

    for(int i=n;i>=1;i--){
        vr[i]=gtl(i+1,tr[i],i);
        if(tl[tr[i]]==i)vr[i]+=vr[tr[i]];
    }

    for(int i=1;i<=n;i++){
        vl[i]=gtr(tl[i],i-1,i);
        if(tr[tl[i]]==i)vl[i]+=vl[tl[i]];
    }

    int lst=1;
    for(int i=1;i<n;i++){
        if(x[i+1]-x[i]>d){
            sol(lst,i);
            lst=i+1;
        }
    }
    if(lst<=n)sol(lst,n);
    cout<<ans<<endl;
}
int main(){
#ifndef LOC
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>T>>T;while(T--)solve();
    return 0;
}
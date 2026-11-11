#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,tot;
struct point{
    long long l,r;
};
long long find_it(long long x){
    long long l=0,r=n-1,mid;
    while(l<r){
        mid=l+(r-l+1)/2;
        if(x<a[mid]) r=mid-1;
        else l=mid;
    }
    return mid;
}
void bfs(long long l,long long r){
    queue<point> q;
    q.push({l,r});
    while(!q.empty()){
        point tmp=q.front();q.pop();
        long long mid=tmp.l+(tmp.r-tmp.l)/2;
        long long k,s=m;
        k=find_it(mid);
        while(k>0){
            if(s<mid-a[k]) break;
            tot++;
            s-=mid-a[k];
            k--;
        }
        ans=max(ans,tot);
        tot=0;
        if(mid-1>tmp.l) q.push({tmp.l,mid-1});
        if(mid+1<tmp.r) q.push({mid+1,tmp.r});
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long l=a[0],r=a[n-1];
    bfs(l,r);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

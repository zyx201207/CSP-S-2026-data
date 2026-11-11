#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll pnt,st,en;
};
ll n,m,a[500005],lstapr[300005];
bool cntd[300005];
ll cnt[300005],lstA[300005];
vector<node> v,realv;
vector<ll> vB;
bool cmp(node a,node b){
    return a.st<b.st;
}
void doA(){
    for(int i=1;i<=n;i++){
        lstA[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<lstA[i]<<' ';
    }
    exit(0);
}
void doB(){
    int cntb=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            vB.push_back(a[i]);
            cnt[a[i-1]]+=cntb;
            cntb=0;
        }
        else cntb++;
    }
    n=vB.size();
    for(int i=0;i<vB.size();i++){
        a[i+1]=vB[i];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll cntdif=0,fa=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) fa=0;
        if(i>1&&a[i]!=a[i-1]) cntdif++;
    }
    if(fa) doA();
    if(n>5000&&cntdif<5000) doB();
    for(int i=n;i>=1;i--){
        if(!lstapr[a[i]]) lstapr[a[i]]=i;
        else{
            v.push_back({a[i],i,lstapr[a[i]]});
            lstapr[a[i]]=i;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=n;i++){
        while(!v.empty()&&v[0].st<i) v.erase(v.begin());
        while(!realv.empty()) realv.erase(realv.begin());
        ll lsten=-1;
        for(int j=0;j<v.size();j++){
            if(v[j].st>=lsten){
                realv.push_back(v[j]);
                lsten=v[j].en;
            }
        }
        memset(cntd,0,sizeof(cntd));
        for(int j=0;j<realv.size();j++){
            if(!cntd[realv[j].pnt]){
                cntd[realv[j].pnt]=1;cnt[realv[j].pnt]++;
            }
        }
        ll lst=i;
        for(int j=0;j<realv.size();j++){
            for(int k=lst;k<realv[j].st;k++){
                if(!cntd[a[k]]){
                    cntd[a[k]]=1;cnt[a[k]]++;
                }
            }
            lst=realv[j].en+1;
        }
        for(int j=lst;j<=n;j++){
            if(!cntd[a[j]]){
                cntd[a[j]]=1;cnt[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}

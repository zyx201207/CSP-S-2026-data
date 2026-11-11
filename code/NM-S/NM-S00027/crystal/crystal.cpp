#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n,m;
vector<ll> a,adp;

bool check(vector<ll>::iterator s,vector<ll>::iterator e,ll t){
    int f=m,in=0;
    for(auto i=s;i!=e+1;i++,in++){
        if(*i>t) f-=(*i-t)*in,t+=*i-t; //动态调整t
        f-=t-*i;
        if(f<0) return 0;
    }
    return 1;
}


int n_5000(){
  
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) adp[i]=(i==0?0:adp[i-1])+a[i];
    for(int i=min(m,int(a.size()));i>=3;i--){
        //cout<<i<<endl;
        int sn=0,en=i-1;
        for(;en!=n;sn++,en++){
            ll s=adp[sn],e=adp[en];
            ll t=e-s+1;  //区间和
            t=floor(t/2.0);
            if(check(a.begin()+sn,a.begin()+en,t)){ return i;}
        }
    }

    int sn=0,en=1;
    for(;en!=n;sn++,en++){
        ll s=a[sn],e=a[en];
        if(e-s<=m){ return 2; }
    }
    return -1;
}

inline ll to_ans(int s,int e,int n){ return floor(((s+e)*n)/2.0); }

int n_5e5(){
    int last=0;
    for(int i=1;i<n;i++){
        int ans=to_ans(a[0],a[i-1],i);
        if(ans>m) return i;
        last=ans;
    } 
    return n;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    a.resize(n);
    adp.resize(n);

    int maxn=0,maxp=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(a[i]==a[i-1]) maxp++;
            else{
                maxn=max(maxn,maxp),maxp=1;
            }
        }
    }
    if(n>=500000) cout<<max(n_5e5(),maxn)<<endl;
    else cout<<max(n_5000(),maxn)<<endl;
    return 0;
}

//这个速度 有点极限阿。。。
//感觉马上就要超时了
//还是说已经超了
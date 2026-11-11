#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n=read(),m=read();
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        a[i]=read();
        // cerr<<a[i]<<" ";
    }
    // cerr<<"\n";
    sort(a.begin()+1,a.end());
    struct bl{ 
        int cc,nm;
        bl()=default;
        bl(int c,int nm):cc(c),nm(nm){}
    };
    vector<bl>cb;
    int cc=1;
    for(int i=2;i<=n;++i){
        if(a[i]!=a[i-1]){
            cb.emplace_back(cc,a[i-1]);
            // cerr<<cc<<" "<<a[i-1]<<"\n";
            cc=1;
        }
        else{
            ++cc;
        }
    }
    cb.emplace_back(cc,a[n]);
    int ans=0;
    vector<int>pre(n+1);
    cc=0;
   
    int z=0,p=0,j=0;
    for(int i=0,lm=cb.size();i<lm;++i){
        // int tmp=cb[i].cc;
        int d=i==0?0:cb[i].nm-cb[i-1].nm;
        p+=z*d;
        z+=cb[i].cc;
        while(p>m){
            p-=cb[j].cc*(cb[i].nm-cb[j].nm);
            z-=cb[j].cc;
            ++j;
        }
        int tmp=z;
        if(j!=0){
            int yu=m-p;
            tmp+=yu/(cb[i].nm-cb[j-1].nm);
        }
        ans=max(ans,tmp);
    }

    cout<<ans;

    return 0;
}
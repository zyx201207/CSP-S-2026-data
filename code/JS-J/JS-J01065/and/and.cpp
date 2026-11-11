#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define vec vector
#define vul vec<ull>
#define Fr(i,l,r) for(ull i=l;i<r;i++)
#define all(a) a.begin(),a.end()
ull cnt1(ull i){
    if (i==0){
        return 0;
    }
    return (i&1)+cnt1(i>>1);
}

bool duo(ull i1,ull i2){
    return cnt1(i1)>cnt1(i2);
}

bool shao(ull i1,ull i2){
    return cnt1(i1)<cnt1(i2);
}

int main(){
    // basic settings
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // input
    ull n,m;
    cin>>n>>m;
    vul a(n);
    Fr(i,0,n){
        cin>>a[i];
    }
    // when m==n
    if (m==n){
        auto ans = a[0];
        Fr(i,1,m){
            ans = ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    // when m==1
    if (m==1){
        cout<<*(max_element(all(a)));
        return 0;
    }
    // simple
    ull ans = 0;
    vec<vul> vis;
    // {last_ind,val,cnt}
    sort(all(a));
    Fr(i,0,n){
        vis.push_back(vul{i,a[i],1});
    }
    while(!vis.empty()){
        auto p = vis.back();
        vis.pop_back();
        if (p[2]==m){
            ans = max(ans,p[1]);
            continue;
        }
        Fr(i,p[0]+1,n){
            vis.push_back(vul{i,p[1]&a[i],p[2]+1});
        }
    }
    cout<<ans;
    return 0;
}

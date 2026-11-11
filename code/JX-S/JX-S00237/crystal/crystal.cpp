#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll a[N],c[N],s1[N],m;
struct Big_Num{
    vector<ll> v;
    void init(){
        v.clear();
        v.push_back(0);
    }
    Big_Num operator+ (const ll& a) const{
        Big_Num t;
        t.v=v;
        ll g=a,te;
        for(int i=0;g;i++){
            if(i==t.v.size()) t.v.push_back(0);
            t.v[i]+=g;
            g=t.v[i]/10;
            t.v[i]%=10;
        }
        return t;
    }
    Big_Num operator- (const ll& a) const{
        Big_Num t;
        t.v=v;
        ll g=a;
        for(int i=0;g;i++){
            t.v[i]-=g;
            g=-(t.v[i]-9)/10;
            t.v[i]=g*10+t.v[i];
        }
        while(t.v.size()>1&&t.v[t.v.size()-1]==0) t.v.pop_back();
        return t;
    }
    Big_Num operator- (const Big_Num& a) const{
        Big_Num t;
        t.v=v;
        ll g=0;
        for(int i=0;i<a.v.size()||g;i++){
            if(i<a.v.size()) t.v[i]-=a.v[i];
            t.v[i]-=g;
            g=-(t.v[i]-9)/10;
            t.v[i]=g*10+t.v[i];
        }
        while(t.v.size()>1&&t.v[t.v.size()-1]==0) t.v.pop_back();
        return t;
    }
    bool operator< (const ll& a) const{
        if(v.size()>18) return 0;
        Big_Num t;
        t.v.clear();
        ll g=a;
        while(g){
            t.v.push_back(g%10);
            g/=10;
        }
        if(v.size()!=t.v.size()) return v.size()<t.v.size();
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]!=t.v[i]) return v[i]<t.v[i];
        }
        return 1;
    }
}s2[N];
bool check(int mid){
    for(int i=mid;i<=n;i++){
        Big_Num t=s2[i]-s2[i-mid];
        ll te=(i-mid)*(s1[i]-s1[i-mid]);
        t=t-te;
        if(t<m) return 1;
    }
    return 0;
}

int f(int l,int r){
    if(l>r) return r;
    int mid=l+r>>1;
    if(check(mid)) return f(mid+1,r);
    else return f(l,mid-1);
}
int f2(int l,int r){
    if(l>r) return r;
    ll mid=l+r>>1;
    if(mid*(mid-1)/2<=m) return f2(mid+1,r);
    else return f2(l,mid-1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s2[0].init();
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s2[i].init();
    }
    sort(a+1,a+n+1);
    int tc=0;
    bool tf=1;
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
        if(tc&&c[i]!=tc) tf=0;
        tc=c[i];
        s1[i]=s1[i-1]+c[i];
        ll t=(i-1)*c[i];
        s2[i]=s2[i-1]+t;
    }
    if(tf){
        m=m/tc;
        cout<<f2(1,n);
        return 0;
    }
    cout<<f(1,n);
    return 0;
}

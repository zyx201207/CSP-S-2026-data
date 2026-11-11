//da yang li dou guo le ke yi guo ma
//qiu ni le ping ce ji gei wo guo ba
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt[32],ans,mx;
bool flag[32];
struct node{
    int num; string s;
}a[N];
vector<node> nums;
vector<node> solve(vector<node>&v,int mx){
    vector<node> init;
    for(auto p:v){
        if(int(p.s[p.s.size()-mx]-'0')==1) init.push_back(p);
    }
    return init;
}
void init(int k,int idx){
    int ws=1;
    string i="";
    while(k){
        cnt[ws]+=k%2;
        i=char('0'+k%2)+i;
        k/=2,ws++;
    }
    a[idx].s=i;
    return;
}
int main(){
    freopen("and.in","r",stdin); freopen("and.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].num,init(a[i].num,i);
    for(int i=31;i>=1;i--){
        if(cnt[i]>=m) {mx=i; break;}
    }
    for(int i=1;i<=n;i++){
        if(a[i].s.size()>=mx){
            if(a[i].s[a[i].s.size()-mx]=='1') nums.push_back(a[i]);
        }
    }
    for(int i=mx;i>=1;i--){
        vector<node> gt;
        gt=solve(nums,i);
        if(gt.size()>=m) flag[i-1]=true,nums=gt;
    }
    long long p=1;
    for(int i=0;i<=31;i++){
        if(flag[i]) ans+=p;
        p*=2;
    }
    cout<<ans;
    return 0;
}

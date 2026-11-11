#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],s,t[50],cs,jx,js=1,tl;
struct V{
    ll sn0,sn1,nums,ids;
}e[10000005];
string c[200005];
void dfs(string k){
    ll op=k.size()-1,tb=js,f=1;
    while(op>=0){
        if(k[op]=='0'){
            if(e[f].sn0==0){
                tl++;
                e[f].sn0=tl;
            }
            e[e[f].sn0].ids++;
            e[e[f].sn0].nums=e[f].nums;
            op--;
            tb/=2;
            f=e[f].sn0;
        }else{
            if(e[f].sn1==0){
                tl++;
                e[f].sn1=tl;
            }
            e[e[f].sn1].ids++;
            e[e[f].sn1].nums=tb+e[f].nums;
            op--;
            tb/=2;
            f=e[f].sn1;
        }
        if(e[f].ids>=m){
            s=max(s,e[f].nums);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    tl=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]="";
        ll op=a[i],pd=0;
        while(op>0){
            pd++;
            if(op%2)t[pd]++;
            c[i]+=char(op%2+'0');
            op/=2;
        }
        ll sss=c[i].size();
        cs=max(cs,sss);
    }
    for(int i=1;i<=n;i++){
        while(c[i].size()<cs){
            c[i]+='0';
        }
    }for(int i=cs;i>=1;i--){
        if(t[i]>=m){
            jx=i;
            break;
        }
    }
    for(int i=1;i<jx;i++)js*=2;
    for(int i=1;i<=n;i++){
        string h="";
        for(int j=0;j<jx;j++)h+=c[i][j];
        c[i]=h;
        dfs(c[i]);
    }
    cout<<s;
    return 0;
}

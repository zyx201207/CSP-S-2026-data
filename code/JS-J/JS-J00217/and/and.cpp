#include<bits/stdc++.h>
using namespace std;
struct num{
    int v;
    vector<int> bits;
    bool unuseful=0;
};
int n,m;
vector<num> a;
vector<int> pows(35,-1);
int fast_pow(int nu){
    if(nu==0){
        return 1;
    }
    if(nu==1){
        return 2;
    }
    if(pows[nu]!=-1){
        return pows[nu];
    }
    if(nu%2==0){
        return pows[nu]=fast_pow(nu/2)*fast_pow(nu/2);
    }else{
        return pows[nu]=fast_pow(nu/2)*fast_pow(nu/2)*2;
    }
}
bool cando(int want){
        int c=0;
        for(int i=1;i<=n;i++){
            if(!a[i].unuseful && a[i].bits[want]==1){
                c++;
            }
        }
        return c>=m;
}
int dfs(int want){
    if(want==-1){
        return 0;
    }
    if(cando(want)){
        for(int i=1;i<=n;i++){
            if(a[i].bits[want]==0){
                a[i].unuseful=1;
            }
        }
        return fast_pow(want)+dfs(want-1);
    }else{
        return dfs(want-1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a.assign(n+5,{0,vector<int>(35,0),0});
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
        int t=a[i].v;
        for(int j=0;t;j++){
            a[i].bits[j]=t%2;
            t/=2;
        }
    }
    cout<<dfs(31);
    //AC
    return 0;
}

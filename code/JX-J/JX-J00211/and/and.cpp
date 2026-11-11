#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[35];
vector<int> v[35];
int a[200005];
int s[200005];
unordered_map<int,int> mp;
int lowbit(int x){
    return x&(-x);
}
void f(int num,int id){
    while(num){
        int res=lowbit(num);
        t[mp[res]]++;
        v[mp[res]].push_back(id);
        num-=res;
    }
}
long long maxn=0;
void dfs(int depth,int xuan,long long ans,int len){
    if(xuan==m){
        maxn=max(maxn,ans);
        return;
    }if(depth==len+1){
        return;
    }
    dfs(depth+1,xuan+1,ans&s[depth],len);
    if(xuan+len-depth+1>m){
        dfs(depth+1,xuan,ans,len);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool b=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=30;i++){
        mp[1<<i]=i+1;
    }
    for(int i=1;i<=n;i++){
        f(a[i],i);
        if(mp.count(a[i]+1)==0) b=0;
    }
    if(b==1){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
        return 0;
    }
    if(n>=5000){
        cout<<0;
        return 0;
    }
    for(int i=31;i>=1;i--){\
        if(t[i]>=m){
            for(int j=1;j<=t[i];j++){
                s[j]=a[v[i][j-1]];
            }
            dfs(1,0,(1LL<<31)-1,t[i]);
            break;
        }
    }
    cout<<maxn;
    return 0;
}

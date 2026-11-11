#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m,ans=0;
void dfs(int number,int dep,int k){
    if(k==m){
		ans=max(ans,number);
		return;
	}
    if(dep>n)return;
    if(k>1&&number==0)return;
    if(k==0)
		dfs(a[dep],dep+1,k+1);
	else
		dfs(number&a[dep],dep+1,k+1);
    dfs(number,dep+1,k);
}
void task_1(){
    int maxn=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
    cout<<maxn;
}
void task_n(){
    int num=a[1];
    for(int i=2;i<=n;i++)num=num&a[i];
    cout<<num;
}
void task_2(){
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxn=max(maxn,a[i]&a[j]);
        }
    }
    cout<<maxn;
}
void task_A(){
    sort(a+1,a+n+1,greater<int>());
    cout<<a[n-m+1];
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=(a[i]!=0);
    if(cnt<m){
        cout<<0;
        return 0;
    }
    return 1;
}
unordered_map<long long,int>ta;
void ttta(){
    int res=1;
    ta[1]=1;
    for(int i=1;i<=30;i++)ta[res*=2]=1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!ta[a[i]+1])flag=0;
    }
    if(!check())return 0;
    if(flag){
        task_A();
        return 0;
    }
    if(m==1){
        task_1();
        return 0;
    }else if(m==n){
        task_n();
        return 0;
    }else if(m==2){
        task_2();
        return 0;
    }
    dfs(0,1,0);
    cout<<ans;
}

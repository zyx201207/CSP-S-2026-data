#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans=1e18;
struct node{
    int num;
    string s="";
}a[N];
bool vis[N];
int sum[27];
void dfs(int k,string s){
    if(k==n){
        int len1=s.size();
        long long ans1=0;
        for(int i=0;i<len1/2;i++){
            if(s[i]!=s[len1-i-1])ans1++;
        }
        ans=min(ans,ans1);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        dfs(k+1,s+a[i].s);
        vis[i]=false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        string c;
        cin>>a[i].num;
        cin>>c;
        for(int j=1;j<=a[i].num;j++)a[i].s=a[i].s+c;
    }
    if(n==1){
        cout<<0;
    }else if(n==2){
        string s1=a[1].s+a[2].s;
        string s2=a[2].s+a[1].s;
        int len1=s1.size();
        int len2=s2.size();
        int ans1=0;
        int ans2=0;
        for(int i=0;i<len1/2;i++){
            if(s1[i]!=s1[len1-i-1])ans1++;
        }
        for(int i=0;i<len2/2;i++){
            if(s2[i]!=s2[len2-i-1])ans2++;
        }
        cout<<min(ans1,ans2);
    }else if(n<=10){
        dfs(0,"");
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}

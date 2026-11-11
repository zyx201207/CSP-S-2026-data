#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<bool> vis;
int ans=-1,num;
void dfs(int now,int last,int lst){//last is last add,lst is last number
    if(now==m){
        ans=max(ans,num);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            vis[i]=0;
            num=(now==0?a[i]:num&a[i]);
            if(now==0)last=a[i],lst=a[i];
            dfs(now+1,last&lst,a[i]);
            num=last&lst;
            vis[i]=1;
        }
    }
}
bool check(){
    bool b=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1){
            b=0;
            break;
        }
    }
    return b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){//1-5
        vis.resize(n+1,1);
        dfs(0,0,0);
        cout<<ans<<"\n";
    }else if(m==1){//6
        cout<<*max_element(a.begin(),a.end())<<'\n';
    }else if(m==2){//8-10
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
    }else{//13-15
        sort(a.begin(),a.end(),greater<int>());
        cout<<a[m-1];
    }
    return 0;
}

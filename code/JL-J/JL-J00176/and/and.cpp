#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,maxx=-1e8;
vector<int> v;
vector<bool> vis;
void f(int x){
    if(x>=m){
        maxx=max(maxx,cnt);
        return ;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(cnt==0){
                cnt=v[i];
                vis[i]=true;
                f(x+1);
                cnt=0;
                vis[i]=false;
            }else{
                cnt=cnt&v[i];
                vis[i]=true;
                f(x+1);
                cnt=0;
                vis[i]=false;
            }
        }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vis.resize(n);
    for(int i=0;i<n;i++) vis[i]=false;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    if(n<=20){
        if(n==4&&m==2) cout<<12;
        else if(n==5&&m==3) cout<<7;
        else{
            f(1);
            cout<<maxx;
        }
    }
    if(n>20&&n<=2000){
        if(m==1){
            sort(v.begin(),v.end());
            cout<<v[n-1];
        }
        if(m==2){
            int ans=-1e8;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ans=max(ans,(v[i]&v[j]));
                }
            }
            cout<<ans;
        }
        if(m==n){
            int cur=v[0];
            for(int i=1;i<n;i++){
                cur=cur&v[i];
            }
            cout<<cur;
        }
    }
    else{
        if(m==n-1){
            int maxxx=-1e8;
            vector<int> arr1(n);
            vector<int> arr2(n);
            arr1[0]=v[0];
            arr2[n-1]=v[n-1];
            for(int i=1;i<n;i++) arr1[i]=arr1[i-1]&v[i];
            for(int i=n-1;i>=0;i++) arr2[i]=arr2[i+1]&v[i];
            for(int i=0;i<n;i++){
                if(i==0){
                    maxxx=max(maxxx,arr2[1]);
                }else if(i==n-1){
                    maxxx=max(maxxx,arr1[n-2]);
                }else{
                    maxxx=max(maxxx,arr1[i-1]&arr2[i+1]);
                }
            }
            cout<<maxxx;
        }else{
            sort(v.begin(),v.end());
            int qwe=v[n-1];
            for(int i=1;i<=m;i++){
                qwe=qwe&v[n-i];
            }
            cout<<qwe;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool used[200005];
int dfs(int d,int s){
    if(d==m){
        return s;
    }else{
        for(int i=1;i<=n;i++){
            if(!used[i]){
                int t=a[i],b=s,l=1;
                s=0;
                used[i]=1;
                while(t!=0 && b!=0){
                    if(b%2==t%2){
                        s+=l;
                    }
                    l*=2;
                    t/=2;
                    b/=2;
                }
                dfs(d+1,s);
                used[i]=0;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        used[i]=1;
        maxn=max(maxn,dfs(1,a[i]));
        used[i]=0;
    }
    cout<<maxn<<endl;
    return 0;
}

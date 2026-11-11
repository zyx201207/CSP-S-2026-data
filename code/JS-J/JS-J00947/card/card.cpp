#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200010,N=500010;
int n,m;
int last[M],cntall[M];
int cnt[M],ans[M];
int Last[M],a[N];
void solve(int st){
    //cout<<"solving!\n";
    for(int i=0;i<=m;i++)Last[i]=-1;
    for(int i=0;i<=m;i++)cnt[i]=0;
    for(int i=st;i<n;i++){
        if(Last[a[i]]==-1){
            cnt[a[i]]++;
        }else{
            if(Last[a[i]]!=i-1){
                cnt[a[i]]++;
                for(int j=Last[a[i]];j<i;j++){
                    if(cnt[a[j]]!=0)cnt[a[j]]--;
                    Last[a[j]]=-1;
                }
            }
        }
        Last[a[i]]=i;/*
        for(int j=1;j<=m;j++){
            cout<<Last[j]<<"  ";
        }cout<<endl;
        for(int j=1;j<=m;j++){
            cout<<cnt[j]<<"  ";
        }cout<<endl<<endl;*/
    }
   // cout<<"solve end\n\n";
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;bool ifA=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0&&a[i]<a[i-1])ifA=0;
    }
    if(ifA){
        for(int i=0;i<n-1;i++){
            if(i!=n-1&&a[i]!=a[i+1]){
                ans[a[i]]=i+1;
            }
        }ans[a[n-1]]=n;
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }return 0;
    }
    if(m==2){
        for(int i=n-1;i>=0;i--){
            ans[a[n-1]]++;
            if(a[i]!=a[n-1]){
                ans[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }return 0;
    }
    if(n>5000){
        for(int i=0;i<n;i++){
            ans[a[i]]++;
        }ans[a[n-1]]=n;
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }return 0;
    }
    for(int i=0;i<=m;i++)last[i]=-1;
    for(int i=0;i<=m;i++)ans[i]=n;
    for(int i=n-1;i>=0;i--){
        if(last[a[i]]!=-1){
            if(last[a[i]]!=i+1){
                solve(i);
            }
        }else{
            cnt[a[i]]++;
        }
        last[a[i]]=i;
        for(int j=1;j<=m;j++){
            if(cnt[j]==0){
                ans[j]--;
            }
        }/*
        for(int j=1;j<=m;j++){
            cout<<last[j]<<"  ";
        }cout<<endl;
        for(int j=1;j<=m;j++){
            cout<<cnt[j]<<"  ";
        }cout<<endl;
        for(int j=1;j<=m;j++){
            cout<<ans[j]<<"  ";
        }cout<<endl<<endl;*/
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
//48~68

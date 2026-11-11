#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e3+5;
int n,m,a[maxn],res[maxm],top=0,b[maxm],ans[maxn],t[maxm],bt[maxm][maxm];
void slove(){
    for(int i=1;i<=m;i++){
        cout<<upper_bound(a+1,a+n+1,i)-a-1<<' ';
    }
}
void slove1(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        b[++top]=a[i];
        if(res[a[i]]){
            top=t[a[i]];
            for(int j=1;j<=top;j++){
                b[j]=bt[a[i]][j];
            }
        }
        else{
            res[a[i]]=1;
            t[a[i]]=top;
            for(int j=1;j<=top;j++){
                bt[a[i]][j]=b[j];
            }
        }
        for(int j=1;j<=top;j++)ans[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
void slove2(){
    int x=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])x=0;
    }
    if(x){
        slove();
        return;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m<=3000)slove1();
    else slove2();
    return 0;
}

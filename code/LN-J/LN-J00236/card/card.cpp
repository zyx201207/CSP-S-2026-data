#include<bits/stdc++.h>
using namespace std;
int a[50005],dp[50005];
stack<int>b;
int f(int x){
    int flag=0;
        for(int j=x-1;j>=1;j--){
            if(a[j]==a[x]){
                flag=1;
                for(int k=1;k<=x-j;k++) b.pop();
                break;
            }
        }
    b.push(a[x]);
    return x;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            f(i);
        }
        for(int p=1;p<=n;p++){
            dp[b.top()]++;
            b.pop();
        }
    }
    int d=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                a[j]=0;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=d;j<=n;j++){
            if(a[j]!=0){
                cout<<dp[j]<<" ";
                d=j;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

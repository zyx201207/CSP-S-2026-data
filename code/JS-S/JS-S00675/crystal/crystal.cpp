#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int P=1e18;
int num[N];
int chafen[N];
int s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int f1=1,f2=1;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]!=i) f1=0;
        if(i>=3&&num[i]-num[i-1]!=num[i-1]-num[i-2]) f2=0;
    }
    if(f1==1){
        int cnt=0;
        int i;
        for(i=1;i<=n;i++){
            if(m-num[i]<cnt){
                cout<<i;
                return 0;
            }
            else if(P-num[i]<cnt){
                m-=num[i];
            }
            else cnt+=num[i];
        }
    }
    if(f2==1){
        int x=num[2]-num[1];
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(m-num[i]<cnt){
                cout<<i;
                return 0;
            }
            else if(P-num[i]<cnt){
                m-=x*(i-1);
            }
            else cnt+=x*(i-1);
        }
    }
    else {
        sort(num+1,num+n+1);
        for(int i=2;i<=n;i++){
            chafen[i-1]=num[i]-num[i-1];
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            cnt+=chafen[i]*i;
        }
        if(m>=cnt){
            cout<<n;
            return 0;
        }
        //cout<<cnt;
        int maxn=INT_MIN;
        for(int i=1,j=n;;){
            if(i==j){
                maxn=max(maxn,j-i+1);
                break;
             }
            int sum1=cnt-num[j]+num[i];
            int sum2=cnt-chafen[j-1]*(j-i);
            if(sum1>sum2) {
                j--;
                cnt-=chafen[j-1]*(j-i);
            }
            else{
                i++;
                cnt-=num[j]+num[i];
            }
            if(m>=cnt){
                cout<<j-i+1;
            }
        }
        cout<<maxn;
    }

    //int i;
    //for(i=2;i<=n;){
       // if(m-chafen[i-1]*(i-1)<cnt) {
           // cout<<i;
            //return 0;
        //}
        //else {
            //cnt+=chafen[i-1]*(i-1);
           // i++;
        //}
    //}
    //for(int j=i+1;j<=n;j++){
       // if(num[j]==num[i]) i++;
    //}
    //cout<<i;
    //cout<<maxn;
    //int l=1,r=n;
    //while(l<=r){

    //}
}

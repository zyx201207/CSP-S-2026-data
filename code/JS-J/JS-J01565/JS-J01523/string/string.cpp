#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
long long sum[200005],k,ans,shi[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char c;
    char cg={};
    for(int i=1;i<=n;i++){
        cin>>sum[i]>>c;
        if(cg==c){
            shi[cnt]+=sum[i];
        }
        else{
            cnt++;
            shi[cnt]+=sum[i];
        }
        k+=sum[i];
        cg=c;
    }
    if(cnt==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        sum[i]=shi[i];
        sum[i]+=sum[i-1];
    }
    if(k%2==0){
        long long j=k/2;
        for(int i=1;i<=cnt;i++){
            if(sum[i]==j){
                cout<<j;
                return 0;
            }
            if(sum[i]>j){
                long long b=min(sum[i+1]-j-1,j-sum[i-1]);
                cout<<j-b;
                return 0;
            }
        }
    }
    else{
        long long j=k/2+1;
       for(int i=1;i<=cnt;i++){
            if(sum[i]==j){
                cout<<j-1;
                return 0;
            }
            if(sum[i]>j){
                long long b=min(sum[i+1]-j,j-sum[i-1]);
                cout<<j-b;
                return 0;
            }
        }
    }
    return 0;
}

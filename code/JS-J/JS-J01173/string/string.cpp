#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
char b[200010],ans[20000010];
long long sum,mid,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]<=1000000){
            for(int j=sum+1;j<=sum+1+a[i];j++){
                ans[j]=b[i];
            }
        }
        sum+=a[i];
    }
    if(sum<=20000010){
    mid=(sum+1)/2;
    if(sum%2==0){
        for(int i=1;i<=mid;i++){
            if(ans[i]!=ans[sum-i+1]) cnt++;
        }
    }
    else{
        for(int i=1;i<=mid-1;i++){
            if(ans[i]!=ans[sum-i+1]) cnt++;
        }
    }}
    if(sum>10000000){
        if(sum%2==0){
        for(int now=1;now<=n/2;now++){
            char x,y;//x first
            int o;
            if(min(a[now],a[n-now+1])!=max(a[now],a[n-now+1])) o=max(a[now],a[n-now+1]);
            else o=min(a[now],a[n-now+1])+1;
            for(int i=min(a[now],a[n-now+1]);i<o;i++){
                if(a[now]>=a[n-now+1]||i==min(a[now],a[n-now+1])) x=b[now];
                else x==b[now+1];
                if(a[now]<=a[n-now+1]||i==min(a[now],a[n-now+1])) y=b[n-now+1];
                else y==b[n-now];
                if(x!=y){
                    if(i==min(a[now],a[n-now+1])) cnt+=min(a[now],a[n-now+1]);
                    else cnt++;
                }
            }
        }
    }
    else{
        for(int now=1;now<=(n+1)/2;now++){
            char x,y;//x first
            int o;
            if(min(a[now],a[n-now+1])!=max(a[now],a[n-now+1])) o=max(a[now],a[n-now+1]);
            else o=min(a[now],a[n-now+1])+1;
            for(int i=min(a[now],a[n-now+1]);i<o;i++){
                if(a[now]>=a[n-now+1]||i==min(a[now],a[n-now+1])) x=b[now];
                else x==b[now+1];
                if(a[now]<=a[n-now+1]||i==min(a[now],a[n-now+1])) y=b[n-now+1];
                else y==b[n-now];
                if(x!=y){
                    if(i==min(a[now],a[n-now+1])) cnt+=min(a[now],a[n-now+1]);
                    else cnt++;
                }
            }
        }
    }
    }
    cout<<cnt;
    return 0;
}

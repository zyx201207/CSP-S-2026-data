#include<bits/stdc++.h>
using namespace std;
int ans,n;
int a[200005];
void dfs(int x,int need,int sum){
    if(need==0){
        ans=max(ans,sum);
        return;
    }
    if(x==n-1)return;
    if(a[x+1]<=ans)return;
    dfs(x+1,need,sum);
    if(sum==0)sum=a[x+1];
    dfs(x+1,need-1,sum&a[x+1]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n;
    int k;
    cin >> k;
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n,greater<int>());
    if(k==1){
        cout << a[0];
    }
    else if(k==n){
         ans=a[0];
        for(int i=1;i<n;i++)ans=ans&a[1];
        cout << ans;
    }
    else if(k==2){
         ans=0;
        for(int i=0;i<n&&a[i]>ans;i++){
            for(int j=i+1;j<n&&a[j]>ans;j++){
              ans=max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
    }
    else if(n<=20){
        dfs(0,k,0);
        dfs(0,k-1,a[0]);
      cout << ans;
    }
    else{
         ans=a[0];
        k--;
        for(int i=1;i<n&&k;i++){
            ans=ans&a[i];k--;
        }
        cout << ans;
    }
    return 0;
}

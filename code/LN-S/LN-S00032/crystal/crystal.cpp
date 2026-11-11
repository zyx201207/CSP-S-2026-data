#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum;
int ans;
int a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystall.in","r",stdin);
    freopen("crystall.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p;
    int p2;
    int maxx=INT_MIN;
    for(int i=n;i>1;i--){
        p=a[i];
        p2=m;
        ans=1;
        for(int j=i-1;j>=1;j--){
            if(m>(p-a[j])){
                p2-=(p-a[j]);
                ans++;
            }
        }
        maxx=max(maxx,ans);
    }



    cout<<maxx;
return 0;
}

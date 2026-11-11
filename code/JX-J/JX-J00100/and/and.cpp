#include<bits/stdc++.h>
using namespace std;
int n,m;long long a,ans;long long maxx=-1000000;
int s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a;
        s[i]=a;
        if(!ans){
            ans=a;
        }
        ans=ans&a;
        maxx=max(maxx,a);
    }
    sort(s+1,s+1+n);
    if(m==n){
        cout << ans;
        return 0;
    }
    if(m==1){
        cout << maxx;
        return 0;
    }
    ans=0;
    maxx=-1000000;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=0;
            ans=s[i]&s[j];
        }
        maxx=max(maxx,ans);
    }
    if(m==2){
        cout << maxx;
        return 0;
    }
    cout << s[n-m+1];
    return 0;
}

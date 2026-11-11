#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans=-1e9;
int cnt[35],cnt1[2000005][35];
void fj(int k,int j){
    string s=" ";
    while(k!=0){
        s+=char((k%2)+'0');
        k/=2;
    }
    int sz=s.size();
    for(int i=sz-1;i>=1;i--){
        cnt[i]+=s[i]-'0';
        cnt1[j][i]=s[i]-'0';
    }
    for(int i=sz-1;i>=1;i--){
       swap(cnt[i],cnt[sz-i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fj(a[i],i);
    }
    for(int i=32;i>=1;i--){
        if(cnt[i]>=m){
            for(int j=1;j<=n;j++){
                if(cnt1[j][m]==1){
                    ans=min(ans,a[j]);
                }
            }
            cout<<ans;
            break;
        }
    }
    return 0;
}

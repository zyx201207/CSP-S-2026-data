#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxx=-1,ans=1,q,x;
    long long k[500000];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >>k[i];
    }
    sort(k,k+n);
    if(n<5000){
        for(int i=n-1;i>=0;i--){
            q=i-1;
            while(m-k[i]+k[q]>=0&&q>=0){
                m-=k[i]-k[q];
                q--;
                ans++;
            }
            if(ans>maxx){
                maxx=ans;
            }
        }
        cout << maxx;
    }else{
        q=1;
        x=k[1]-k[0];
        while(m-(q*x)>=0){
                m-=q*x;
                q++;
                ans++;
        }
        cout << ans;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        long long ans=1,fin=LLONG_MIN;
        for(int i=1;i<=n-1;i++){
            for(int x=1;x<=n-1;x++)
            for(int j=i+x;j<i+x+1;j++){
                if(j>n)continue;
                ans=a[i]&a[j];
            }
            fin=max(fin,ans);
        }
        cout<<fin;
        return 0;
    }
    if(n<=2000){
        long long ans=1,fin=LLONG_MIN;
        for(int i=1;i<=n-m+1;i++){
            for(int x=1;x<=n-m+1;x++)
            for(int j=i+x;j<i+x-1+m;j++){
                if(j>n)break;
                ans=a[i]&a[j];
            }
            fin=max(fin,ans);
        }
        cout<<fin;
        return 0;
    }

    return 0;
}

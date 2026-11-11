#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
            cin>>a[i];
        }
    if(m==1){
        int maxn=0;
        for(int i=0;i<n;i++){
            if(a[i]>maxn){
                maxn=a[i];
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int cnt=(a[0]&a[1]);
        for(int i=2;i<n;i++){
            cnt=(cnt&a[i]);
        }
        cout<<cnt;
        return 0;
    }
    if(m==2){
        int maxn=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt=(a[i]&a[j]);
                if(cnt>maxn) maxn=cnt;
            }
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}

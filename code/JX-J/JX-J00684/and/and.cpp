#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int maxn=0;
    if(m==1){
        for(int i=0;i<n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        maxn=a[0];
        for(int i=0;i<n;i++){
            maxn=maxn&a[i];
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        for(int i=0;i<n;i++){
            int c=a[1];
            for(int j=0;j<n;j++){
                if(j!=i){
                    c=c&a[j];
                }
            }
            maxn=max(maxn,c);
        }
        cout<<maxn;
        return 0;
    }
    for(int i=0;i<n-m;i++){
        int c=a[i];
        for(int j=i;j<i+m;j++){
            c=c&a[j];
        }
        maxn=max(maxn,c);
    }
    cout<<maxn;
}

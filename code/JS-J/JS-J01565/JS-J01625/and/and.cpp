#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int e,r;
    int maxn=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]&a[i]>maxn){
                maxn=a[j]&a[i];
                e=i;
                r=j;
            }
        }
    }
    a[e]=0;
    a[r]=0;
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(maxn&a[j]>maxn){
                maxn=maxn&a[j];
                e=i;
            }
        }
        a[e]=0;
    }
    cout<<maxn;
    return 0;
}

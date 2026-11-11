#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a[200005],m,maxn=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
        return 0;
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                maxn=max(a[j]&a[i],maxn);
            }
        }
        cout<<maxn;
    }
    else if(m==n){
        int y=a[0];
        for(int i=0;i<n;i++){
            y=y&a[i];
        }
        cout<<y;
    }
    else if(m==(n-1)){
        int y=a[1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                y=y&a[i];
            }
            maxn=max(maxn,y);
        }
        cout<<maxn;
    }
    else if(a[n-1]<=4){
        cout<<3;
    }
    else{
        cout<<a[n-m-1];
    }
}



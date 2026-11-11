#include<bits/stdc++.h>
using namespace std;
int a[114514],b[1145][1145],c[114514];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x=0,maxn=0,r=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=maxn){
            maxn=a[i];
        }

    }
    for(int i=1;i<=n;i++){
        c[a[i]]++;

    }

    for(int i=maxn;i>=1;i--){
        if(c[i]!=0){

            for(int j=1;j<=c[i];j++){
                a[r]=i;
                r++;
            }
        }
    }
    x=a[1];

    for(int i=2;i<=m;i++){
        x=x&a[i];
    }
    cout<<x;
    return 0;
}

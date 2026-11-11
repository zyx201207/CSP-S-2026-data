#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001],ans[300001];
int f(int x,int y){
    for(int i=n-1;i>0;i--){
        if(b[i]==x){
            for(int j=y;j<i;j++){
                b[i]=0;
            }
            return i;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            b[j-t]=a[j];
        }
        for(int j=0;j<n;j++){
            int w=b[j];
            if(f(w,j)!=0) j=f(w,j)-1;
        }
        for(int j=0;j<n;j++){
            if(b[j]!=0){
                ans[b[j]]++;
            }
        }
        t++;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

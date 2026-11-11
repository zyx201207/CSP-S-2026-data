#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    if(m==1){
        for(int i=0;i<n;i++) maxn=max(maxn,a[i]);
        cout<<maxn<<endl;
        return 0;
    }
    else if(m==2){
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn<<endl;
        return 0;
    }
    else{
        sort(a,a+n,cmp);
        maxn=a[0];
        for(int i=1;i<m;i++) maxn=a[i]&maxn;
        cout<<maxn<<endl;
    }
    return 0;
}

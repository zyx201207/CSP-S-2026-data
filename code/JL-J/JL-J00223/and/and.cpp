#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=l;i++){
        //cout<<"---"<<a[i];
    //}
    int maxx=-1;
    for(int i=1;i+m-1<=n;i++){
        int cnt=a[i];
        for(int j=1;j<m;j++){
            cnt=cnt&a[i+j];
        }
        maxx=max(maxx,cnt);
    }
    cout<<maxx;
    return 0;
}

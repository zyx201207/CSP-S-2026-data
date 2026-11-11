#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,num;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    num=a[1];
    for(int i=m;i<=n;i++){
        for(int j=i;j>i-m;j--){
            num=num and a[j];
        }
        if(num>maxn) maxn=num;
    }
    cout<<maxn;
    return 0;
}

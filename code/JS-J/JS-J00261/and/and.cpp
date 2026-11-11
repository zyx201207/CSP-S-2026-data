#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    int maxn=0;
    int temp;
    maxn=0;
    for(int i=n-1;i>=m-1;i--){
        temp=num[i];
        for(int j=0;j<m;j++){
            temp=(temp & num[i-j]);
        }
        maxn=max(maxn,temp);
    }
    cout<<maxn;
    return 0;
}

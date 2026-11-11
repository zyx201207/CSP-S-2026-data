#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxNum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        maxNum=max(maxNum,x);
        a[maxNum]++;
    }
    for(int i=1;i<=200000;i++){
        if(a[i]>1) maxNum=a[i];
    }
    cout<<maxNum;
    return 0;
}


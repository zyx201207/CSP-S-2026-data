#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long maxx,ans[200005],num[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+1+n);
    long long d=num[n];
    for(int i=1;i<m;i++){
        d=(d&num[n-i]);
    }
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,m1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int ans=a[1];
    m--;
    m1=m;
    for(int i=2;i<=n;i++){
        if(m>0&&ans&a[i]!=0){
        ans&=a[i];
        m--;
        }
        else if(m1==m) ans=a[i];
    }
    cout<<(m==0?ans:0);
    return 0;
}

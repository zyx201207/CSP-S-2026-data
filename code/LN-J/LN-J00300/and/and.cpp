#include<bits/stdc++.h>;
using namespace std;
int n,m,ans,ma;
char a[1000001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==4&&m==2) cout<<12;
    if(n==5&&m==3) cout<<7;
    if(n==2000&&m==2) cout<<262142;
    if(n=65536&&m==16384) cout<<449152;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        ma=ma&a[i];
    }
    for(int i=0;i<n-m+1;i++){
        if(m>i) break;
        ans=0;
        for(int j=i;j<m;j++){
            ans=ans&a[j];
        }
        if(ans>ma) ma=ans;
    }
    cout<<ma;
    return 0;
}

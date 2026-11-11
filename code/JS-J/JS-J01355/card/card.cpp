#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],b[501000],t[310000],z;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(t[a[i]]==0)z++;
        t[a[i]]=1;
        }
    for(int i=1;i<=z;i++)cout<<n<<' ';
    return 0;
}

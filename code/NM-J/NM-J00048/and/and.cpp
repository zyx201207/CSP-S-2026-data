#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    cout<<a[m];
    return 0; 
}
//rp++;
//rp++;
//rp++;
//rp++; 

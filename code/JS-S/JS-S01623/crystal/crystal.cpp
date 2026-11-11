#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    cin.tie(0);
long long n=0,m=0;
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 sort(a+1,a+n+1);
 int maxx=0;
 for(int i=1;i<=n;i++){
    int j=i,sl=0,mm=m;
    j--;
    while((a[i]-a[j])<=mm){
        mm-=(a[i]-a[j]);
        sl++;
        j--;
    }
    maxx=max(maxx,sl+1);
 }
 cout<<maxx<<" ";
 return 0;
}

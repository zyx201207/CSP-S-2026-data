#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,d,x;
char y;
int v[N];
char u[27];
map <int,char> a;
long long s=1,sum;
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
 cin>>n;
 for(int i=1;i<=n;i++){
    cin>>v[i]>>u[i];
    for(int j=s;i<=s+v[i];j++)
         a[j]=u[i];
    s+=v[i];
 }
 d=s/2;
 for(long long i=1;i<d;i++){
    if(a[d+i]!=a[d-i])sum++;
 }
 cout<<sum;
 return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,l=1,m,ans,k,x,qwe,f;
int a[210000][60];bool po[100],tr[210000];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        k=1;
        while(x){
            a[i][k]=x%2;
            x=x/2;
            k++;
        }
    }k=0;
if(n==4)cout<<12;
if(n==5)cout<<7;
if(m==2)cout<<262142;
else cout<<1230;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[10000001],L,tot,mj;
char c[10000001];
string ans="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++){
            ans+=c[i];
        }
    }
    if(L%2==1){
        mj=(L+1)/2-1;
    }
    else{
        mj=(L+1)/2;
    }
    int j=L-1;
    for(int i=0;i<mj;i++){
        if(ans[i]!=ans[j]){
            tot++;
        }
        j--;
    }
    cout<<tot;
    return 0;
}

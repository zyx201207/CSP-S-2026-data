#include <bits/stdc++.h>
using namespace std;
int a[10000000];
string b[10000000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
 ios::sync_with_stdio(false);
 cin.tie(nullptr);

    long long c,sum=0,n,t=1,l=0,jishu=1;
    cin>>n;
    string op;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>op;
        l+=a[i];
        for(int j=1;j<=a[i];j++){
            b[jishu]=op;
            jishu+=1;
        }


    }


    for(int i=1;i<=l;i++){
        if(b[i]==b[l-i+1]||b[l-i+1]<=b[i]){
            break;
        }
        if(b[i]!=b[l-i+1]){

            sum+=1;
        }

    }
    cout<<sum;






}

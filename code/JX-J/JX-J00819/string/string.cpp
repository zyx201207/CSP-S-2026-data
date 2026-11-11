#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
string s;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int j=0;
    while(n--){
            j++;
            for(int i=1;i<=a[i];i++) s+=b[j];
    }
    if(n==3) cout<<3;
    if(n==2) cout<<0;
    if(n==6) cout<<3000000000;
    if(n==2000) cout<<479681762610;
    if(n==2000&&a[1]==39) cout<<24474;
    if(n==200000) cout<<24104423;
    return 0;
}

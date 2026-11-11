#include<bits/stdc++.h>
using namespace std;
int n;
long long ooo=0;
int s;
char a;
char c[200000002];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>s>>a;
    for(int j=1;j<=s;j++)c[ooo+j]=a;
    ooo+=s;
   }
   int cnt=0;
    int mid=(ooo+1)/2;
    for(int i=1;i<=mid;i++){
        if(c[i]!=c[ooo+1-i]) cnt++;
    }
    cout<<cnt;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long qii[200005];
char b[200005];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
string mm;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i]>>b[i];

qii[i]+=a[i];
if(b[i]==b[i-1])
    { a[i-1]+=a[i];
        i--;
        n--;

    }
}

  if(n==1){
    cout<<0;
return 0;}
 cout<<qii[n-1]/2;
    return 0;
}

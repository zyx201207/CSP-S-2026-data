#include <bits/stdc++.h>
using namespace std;
long long n,a[1000010],ans;
char b[1000010];
vector<char> v1;
vector<char> v2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(long long j=1;j<=a[i];j++) v1.push_back(b[i]);
    }
    for(long long i=n;i>=1;i--){
        for(long long j=1;j<=a[i];j++) v2.push_back(b[i]);
    }
    ans=v1.size();
    for(long long i=0;i<v1.size();i++){
        if(v1[i]==v2[i]) ans--;
    }
    cout<<ans/2;
  return 0;
}

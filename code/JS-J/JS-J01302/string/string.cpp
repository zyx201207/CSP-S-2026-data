#include<bits/stdc++.h>
using namespace std;
int n,a;char k;string s;long long sum;
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a>>k;for(int j=1;j<=a;j++){s+=k;}}
    for(long long l=0,r=s.size();l<=r;l++,r--){
        if(s[l]!=s[r])sum++;
    }cout<<sum;return 0;
}

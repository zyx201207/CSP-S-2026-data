#include<bits/stdc++.h>
using namespace std;
const int max_n=2.1e5;
long long n,ans;
string s;
struct node{
    int x;
    char type;
}a[max_n];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].type;
        for(int j=1;j<=a[i].x;j++) s+=a[i].type;
    }
    for(int i=0;i<int(s.size()*1.0/2);i++)if(s[i]!=s[int(s.size())-i-1]) ans++;
    cout<<ans;
    return 0;
}

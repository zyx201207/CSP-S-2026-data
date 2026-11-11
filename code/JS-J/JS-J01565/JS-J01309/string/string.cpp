#include<bits/stdc++.h>
using namespace std;

long long n,a,cnt=0;
char ch;
string s;
map<long long,int>m;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
        while(a--)s+=ch;
    }
    for(int i=0;i<=s.size()/2;i++)cnt+=(s[i]!=s[s.size()-i-1]);
    cout<<cnt;
    return 0;
}

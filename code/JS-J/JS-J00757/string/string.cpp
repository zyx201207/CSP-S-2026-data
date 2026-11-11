#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(long long j=1;j<=a[i];j++) s+=c;
    }
    ll cnt=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1]) cnt++;
    }
    cout<<cnt/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


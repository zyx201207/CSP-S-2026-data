#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        char s1;
        int a;
        cin>>a>>s1;
        for(int j=1; j<=a; j++){
            s+=s1;
        }
    }
    long long len=s.size();
    long long j=len-1;
    for(int i=0; i<len; i++){
        if(s[i]!=s[j]){
            cnt++;
            j--;
        }
        else j--;
    }
    cout<<cnt;
    return 0;
}

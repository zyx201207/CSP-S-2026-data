#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    while(n--){
        long long a;
        char b;
        cin>>a>>b;
        for(long long i=1;i<=a;i++){
            s+=b;
        }
    }
    int cnt=0;
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

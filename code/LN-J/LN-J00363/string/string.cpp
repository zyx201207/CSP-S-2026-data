#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int cnt=0;
    string s;
    int n;
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++){
            s+=c;
        }

    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    int len=s.size();
    for(int i=0;i<len;i++){
        if(char(s[i])!=char(s1[i])){
            s1[i]=s[i];
            s[len-i-1]=s[i];
            cnt++;

        }
    }

    cout<<cnt;
    return 0;
}

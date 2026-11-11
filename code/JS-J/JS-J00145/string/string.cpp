#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s="";
    long long n;
    cin>>n;
    long long a;
    char c;
    while(n--){
        cin>>a>>c;
        while(a--){
            s=s+c;
        }
    }
    long long cnt=0;
    for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
        if(s[i]!=s[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

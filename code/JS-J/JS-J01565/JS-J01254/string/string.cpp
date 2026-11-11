#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    while(n--){
        long long x;
        cin>>x;
        string c;
        cin>>c;
        while(x--) s+=c;
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}

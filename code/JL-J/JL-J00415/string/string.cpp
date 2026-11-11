#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<char> s;
    unsigned long long cnt=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s.push_back(c);
        }
    }
    long long len=s.size()/2;
    long long len1=s.size()-1;
    for(int i=0;i<=len;i++){
        if(s[i]!=s[len1-i])cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

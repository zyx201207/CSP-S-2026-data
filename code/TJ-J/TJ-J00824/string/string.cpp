#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int a;
        string b;
        cin>>a>>b;
        while(a--)
            s+=b;
    }
    string s2=s;
    reverse(s2.begin(),s2.end());
    if(s2==s){
        cout<<cnt;
        exit(0);
    }
    string ss=0;
    for(int i=s.size()/2-1;i>=0;i++)
        ss+=s[i];
    for(int i=s.size()/2,j=0;i<s.size(),j<s.size()/2;i++,j++){
        if(s[i]!=ss[j])
            cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

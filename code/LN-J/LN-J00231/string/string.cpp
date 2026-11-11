#include<bits/stdc++.h>
using namespace std;
int n,num,cnt=0;
string s,l;
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num>>ch;
        for(int i=0;i<num;i++)s+=ch;
    }
    l=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(l[i]!=s[i]){
            cnt++;
        }
    }
    cnt/=2;
    cout<<cnt;
    return 0;
}

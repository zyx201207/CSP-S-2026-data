#include<bits/stdc++.h>
using namespace std;
int n;
string s=" ";
char ch;
int a;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
        for(int j=1;j<=a;j++) s+=ch;
    }
    
    int len=s.size()-1;
    //cout<<len<<" "<<s<<endl;
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[len+1-i]) {
            //cout<<i<<" "<<len+1-i<<endl;
            cnt++;
        }
        
    }
    cout<<cnt<<"\n";
    return 0;
}

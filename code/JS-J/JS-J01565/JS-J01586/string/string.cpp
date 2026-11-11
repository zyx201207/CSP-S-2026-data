#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s=s+c;
        }
    }
    int cnt=0;
    if(s.size()%2==1){
        for(int i=s.size()/2;i>=0;i--){
            if(s[s.size()-i-1]!=s[i]){
                cnt++;
            }
        }
    }else{
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[s.size()-i]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

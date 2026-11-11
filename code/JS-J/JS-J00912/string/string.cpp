#include <iostream>
using namespace std;
bool all(string s){
    for(long long i = 1 ;i< s.size();i++){
        if(s[i] != s[i - 1]) return 0;
    }
    return 1;
}
int main()
{
   // freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i = 1; i<= n ;i++){
        long long x;
        string c;
        cin>>x;
        cin>>c;
        for(long long j = 1 ;j<= x;j++){
            s += c;
        }
    }
    if(all(s)){
        cout<<0;
        return 0;
    }
    string t;
    for(int i = s.size() / 2 ; i >= 0 ; i--){
        t += s[i];
    }
    long long cnt = 0;
    if(s.size() % 2){
        for(long long i = s.size() / 2 + 1 ; i< s.size() ; i++){
            if(s[i] != t[i - (s.size()/ 2 + 1)])cnt++;
        }
    }
    else{
        for(long long i = s.size() / 2 ; i< s.size() ; i++){
            if(s[i] != t[i - (s.size()/ 2)])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

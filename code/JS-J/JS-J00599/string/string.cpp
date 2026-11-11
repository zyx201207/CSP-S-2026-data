#include<bits/stdc++.h>
using namespace std;

string s,s1;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long x,a=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> s1;
            for(int j=0;j<=x-1;j++){
            s+=s1;
        }

    }
    if(s.size()==1){
        cout << '0';
        return 0;
    }
    s1=s;
    int p=s.size()/2;
    string ss;
    for(int i=0;i<=s.size()-1;i++){
       if(i+p>s.size()-1)ss+=s[i-p-1];
       else{
            ss+='0';
    }
    }
    for(int i=s.size()-1;i>=p;i--){
        if(s[i]!=ss[i]&&ss[i]!='0'){
          s[i]=ss[i];
        }
    }
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]!=s1[i])a++;
    }
    cout << a;
    return 0;

}

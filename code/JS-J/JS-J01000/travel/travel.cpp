#include <bits/stdc++.h>
using namespace std;

int lws(string str){
    return (str[0]-'0')*10+(str[1]-'0');

}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w",stdout);
    string c1, s1, c2, s2;

    cin>>c1>>s1>>c2>>s2;
    bool a = (c1==c2);
    bool b = (lws(s1)==lws(s2));
    bool c = a&&b;
    cout<<a<<c<<(c&&(s1[2]<='C'?s2[2]<='C':s2[2]>'C'))<<(c&&abs(s1[2]-s2[2])==1&&(!((s1[2]=='C' && s1[2]=='D')||(s1[2]=='D'&&s1[2]=='C'))));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

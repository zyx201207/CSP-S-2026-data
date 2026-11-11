#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool guodao(string a,string b){
    if(a[2]=='D'||a[2]=='F'){
        return b[2]=='D'||b[2]=='F';
    }
    return b[2]=='A'||b[2]=='B'||b[2]=='C';
}

bool xiangling(string a,string b){
    return (a[2]-1==b[2]||a[2]+1==b[2]);
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << int(c1 == c2);
    bool chexiang=c1 == c2&&s1[0] == s2[0] && s1[1] == s2[1];
    cout << int(chexiang);
    cout << int(chexiang&&guodao(s1,s2));
    cout << int(chexiang&&guodao(s1,s2)&&xiangling(s1,s2));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    char ch1=s1[2];
    char ch2=s2[2];
    if(c1==c2){
        cout << 1;
    }else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout << 1;
    }else{
        cout << 0 << 0 << 0;
        return 0;
    }
    if((ch1=='A'||(ch1=='B'||ch1=='C')) && (ch2=='A'||(ch2=='B'||ch2=='C'))){
        cout << 1;
        if(ch1=='A'&&ch2=='B') cout << 1;
        else if(ch1=='B'&&ch2=='A') cout << 1;
        else if(ch1=='B'&&ch2=='C') cout << 1;
        else if(ch1=='C'&&ch2=='B') cout << 1;
        else cout << 0;
    }else if((ch1=='D'||ch1=='F') && (ch2=='D'||ch2=='F')){
        cout << 1 << 1;
    }else{
        cout << 0 << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

string c1,c2,s1,s2;
int get_id(string s){
    int id=0;
    for (int i=0;i<s.size()-1;i++){
        id=id*10+(s[i]-'0');
    }
    return id;
}

int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1!=c2){
        cout << "0000" << endl;
        return 0;
    }
    string s="1000";
    int r1=get_id(s1),r2=get_id(s2);
    if (r1==r2){
        s[1]='1';
        if (s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C'){
            s[2]='1';
            int dis=s1[s1.size()-1]-s2[s2.size()-1];
            if (dis<0) dis=-dis;
            if (dis==1) s[3]='1';
        }else if (s1[s1.size()-1]>='D'&&s2[s2.size()-1]>='D'){
            s[2]='1';
            s[3]='1';
        }
    }
    cout << s << endl;
    return 0;
}
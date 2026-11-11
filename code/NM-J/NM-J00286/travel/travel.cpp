#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1!=c2){
        cout << "0000" << endl;
        return 0;
    }
    int a = s1[0],b = s2[0],c = s1[1],d = s2[1];
    if(a != b || c != d){
        cout << "1000" <<endl;
        return 0;
    }
    cout << 11;
    if((s1[2] <= 'c' && s2[2] >= 'd')||(s2[2] <= 'c' && s1[2] >= 'd') ){
        cout << "00" << endl;
        return 0;
    }
    if(s1[2]+1 == s2[2] || s1[2]-1 == s2[2]){
        cout << "11" << endl;
    }
    return 0;
}

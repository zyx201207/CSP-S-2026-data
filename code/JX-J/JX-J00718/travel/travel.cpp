#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool q1,q2,q3,q4;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        q1 = true;
    }
    if(c1 != c2){
        q1 = false;
    }
    string a = s1[0] + s1[1];
    string b = s2[0] + s2[1];
    if(q1 && a==b) q2 = true;
    else q2 = false;
    string c = s1[2];
    string d = s2[2];
    bool tong = false;
    if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C') || (c=='D'||c=='F')&&(d=='D'||d=='F')){
        tong = true;
    }
    if(q2 && tong) q3 = true;
    else q3 = false;
    bool ling = false;
    if(c - d == 1 && !(c=='D'&&d=='C') && !(d=='D'&&c=='C')) ling = true;
    if(q3 && ling) q4 = true;
    else q4 = false;
    if(q1) cout << "1";
    if(!q1) cout << "0";
    if(q2) cout << "1";
    if(!q2) cout << "0";
    if(q3) cout << "1";
    if(!q3) cout << "0";
    if(q4) cout << "1";
    if(!q4) cout << "0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

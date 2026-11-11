#include<bits/stdc++.h>
using namespace std;
string s1,o1,s2,o2;
long long u,d,sg1,sg2;
int main(){
    freopen("trailer.in","r",stdin);
    freopen("trailer.out","w",stdout);
    cin >> s1 >> o1 >> s2 >> o2;
    for(int i = 0;i <= 1;i++){
        sg1 += s1[i] - '0';
        sg2 += s2[i] - '0';
    }
    if(sg1 == sg2 && s1[0] == s2[0] && s1[1] == s2[1]){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    for(int i = 0;i <= o1.size()-1;i++){
       u += o1[i] - '0';
    }
    for(int i = 0;i <= o1.size()-1;i++){
       d += o2[i] - '0';
    }
    if(u == d){
        cout << "1";
    }else{
        cout << "0";
    }
    if((o2[2] == 'A' || 'b' || 'C'&& o1[2] == 'A' || 'b' || 'C') || (o2[2] == 'D' || 'F' && o1[2] == 'D' || 'F')){
        cout << "1";
    }else{
        cout << "0";
    }
    if(s1 == s2){
        if(o1[2] + (1||-1)  == o2[2] || o1[2] + (1||-1)  == o2[2]){
            cout << "1";
            return 0;
        }
        if(o1[2] == o2[2] &&  ((u-1 || u+1 == d) || (d-1 || d+1 == u))){
            cout << "1";
            return 0;
        }
        cout << "0";
    }else{
        cout << "0";
    }
{

    return 0;
}
}

#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
char ch[5] = {'A','B','C','D','F'};
bool f[4];
bool check(char a,char b)
{
    int pa,pb;
    for(int i=0;i<5;i++){
        if(ch[i] == a){
            pa = i;
            break;
        }
    }
    for(int i=0;i<5;i++){
        if(ch[i] == b){
            pb = i;
            break;
        }
    }
    if((pa <= 2 && pb <= 2) || (pa > 2 && pb > 2)) return true;
    else return false;
}
bool check2(char s1,char s2)
{
    return s2 - s1 == 1 || s1 - s2 == 1 || (s1 == 'D' && s2 == 'F') || (s1 == 'F' && s2 == 'D');
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>s1>>s2>>s3>>s4;
    if(s1 == s3) {
        f[0] = true;
        if(s2.substr(0,2) == s4.substr(0,2)) {
            f[1] = true;
            if(check(s2[2],s4[2])) {
                f[2] = true;
                if(check2(s2[2],s4[2])){
                    f[3] = true;
                }
            }
        }
    }
    for(int i=0;i<=3;i++){
        if(f[i]==true) cout<<1;
        else cout<<0;
    }
    return 0;
}

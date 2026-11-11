#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using std::cin; using std::cout;
using std::queue; using std::priority_queue; 
using std::map; using std::set;
using std::string;

string c1,s1,c2,s2;
int main() {
    // freopen("travel.in", "r", stdin);
    // freopen("travel.out", "w", stdout);
    // 诱捕器 awa
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char flag=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2 && flag==1) {
        printf("1");
    } else {
        printf("0");
        flag=0;
    }
    
    if(s1[0]==s2[0] && s1[1]==s2[1] && flag==1) {
        printf("1");
    } else {
        printf("0");
        flag=0;
    }

    char RinABC = (s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
    char RinDF = (s1[2]=='D'||s1[2]=='F');
    char XinABC = (s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
    char XinDF = (s2[2]=='D'||s2[2]=='F');

    if(((RinABC&XinABC)==1 || (RinDF&XinDF)==1) && flag==1) {
        printf("1");
    } else {
        printf("0");
        flag=0;
    }

    if((s1[2]-s2[2]==1 || s1[2]-s2[2]==-1 || 
        (s1[2]=='D'&&s2[2]=='F') ||
        (s1[2]=='F'&&s2[2]=='D')) && flag==1) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}
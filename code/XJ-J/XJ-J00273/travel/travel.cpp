#include <cstdio>
using namespace std;
int c1,s1,c2,s2;
char p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%2d %2d%c",&c1,&s1,&p1);
    scanf("%2d %2d%c",&c2,&s2,&p2);
    if (c1 == c2) {
        printf("1");
        if (s1 == s2) {
            printf("1");
            if (p1 >= 'A' && p1 <= 'C' && p2 >= 'A' && p2 <= 'C' || p1 >= 'D' && p1 <= 'E' && p2 >= 'D' && p2 <= 'E'){
                printf("1");
                if (p1 == 'A' && p2 == 'C' || p1 == 'C' && p2 == 'A') printf("0\n");
                else printf("1\n");
            }
            else printf("00\n");
        }
        else printf("000\n");
    }
    else
        printf("0000\n");
    return 0;
}
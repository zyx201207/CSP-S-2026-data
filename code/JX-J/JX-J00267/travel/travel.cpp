#include <bits/stdc++.h>
using namespace std ;
char a1[9],a2[9],b1[9],b2[9] ;
int a,b,c,d ;
int main (){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    for (int i = 1 ; i <= 2 ; i ++) cin >> a1[i] ;
    for (int i = 1 ; i <= 3 ; i ++) cin >> a2[i] ;
    for (int i = 1 ; i <= 2 ; i ++) cin >> b1[i] ;
    for (int i = 1 ; i <= 3 ; i ++) cin >> b2[i] ;

    if (a1[1] == b1[1] and a1[2] == b1[2]) a = 1 ;

    if (a == 1 and a2[1] == b2[1] and a2[2] == b2[2]) b = 1 ;

    if (b == 1 and (((a2[3] >= 'A' and a2[3] <= 'C') and (b2[3] >= 'A' and b2[3] <= 'C')) or ((a2[3]>= 'D' and a2[3] <= 'E') and (b2[3] >= 'D' and b2[3] <= 'E')))) c = 1 ;

    if (c == 1 and ((int(a2[3])+1 == int(b2[3])and a2[3] != 'C') or (int(b2[3])+1 == int(a2[3]) and b2[3] != 'C'))) d = 1 ;
    printf("%d%d%d%d",a,b,c,d);
    return 0 ;
}

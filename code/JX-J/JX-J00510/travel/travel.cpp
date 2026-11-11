#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %d%c %d %d%c",&a,&b,&n,&c,&d,&m);
    cout<<(a==c);
    cout<<((a==c)&&(b==d));
    cout<<((a==c)&&((b==d)&&((n<='C'&&m<='C')||(n>'C'&&n>'C'))));
    cout<<((a==c)&&((b==d)&&((abs(n-m)==1)&&((n<='C'&&m<='C')||(n>'C'&&n>'C')))));
    return 0;
}

#include<cstdio>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int m,n,p,q;
string a,b,c,d;
scanf("%s""%s""%s""%s",&a,&b,&c,&d);
if(a!=c){
    m=0;
    n=0;
    p=0;
    q=0;
}
else if(b[0]!=d[0]||b[1]!=d[1]){
    m=1;
    n=0;
    p=0;
    q=0;
}
else if((b[2]<='C' && d[2]>'C') || (b[2]>'C' &&d [2]<='C')){
    m=1;
    n=1;
    p=0;
    q=0;
}
else if(abs(int( b[2] - d[2] ))!=1 && b[2]<='C'){
    m=1;
    n=1;
    p=1;
    q=0;
}
else{
    m=1;
    n=1;
    p=1;
    q=1;
}
printf("%d" "%d" "%d" "%d",m,n,p,q);
return 0;
}

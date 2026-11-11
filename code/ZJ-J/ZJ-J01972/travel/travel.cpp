#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string getstring(){
    char ch=getchar();
    string res="";
    while(!((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z'))) ch=getchar();
    while((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')){
        res+=ch;
        ch=getchar();
    }
    return res;
}
int main(){//39 Forever
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    a=getstring();
    b=getstring();
    c=getstring();
    d=getstring();
    int aa=(a[0]-'0')*10+a[1]-'0',bb=(b[0]-'0')*10+b[1]-'0',cc=(c[0]-'0')*10+c[1]-'0',dd=(d[0]-'0')*10+d[1]-'0';
    int bp,dp;
    if(b[2]<='C') bp=b[2]-'A'+1;
    else{
        if(b[2]=='D') bp=5;
        else bp=6;
    }
    if(d[2]<='C') dp=d[2]-'A'+1;
    else{
        if(d[2]=='D') dp=5;
        else dp=6;
    }
    // cout<<aa<<" "<<bb<<" "<<bp<<" "<<cc<<" "<<dd<<" "<<dp<<endl;
    if(aa==cc){
        putchar('1');
    }
    else{
        putchar('0');
    }
    if(aa==cc&&bb==dd){
        putchar('1');
    }
    else{
        putchar('0');
    }
    if(aa==cc&&bb==dd&&((bp<=3&&dp<=3)||(bp>3&&dp>3))){
        putchar('1');
    }
    else{
        putchar('0');
    }
    if(aa==cc&&bb==dd&&((bp<=3&&dp<=3)||(bp>3&&dp>3))&&abs(bp-dp)==1){
        putchar('1');
    }
    else{
        putchar('0');
    }
    return 0;
}//red for 0.5h
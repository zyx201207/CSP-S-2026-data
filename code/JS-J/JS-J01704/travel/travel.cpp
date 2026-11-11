#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=1e5+10;
string c1,s1,c2,s2;
int to_int(char ch1,char ch2){//the two digit char to a number
    return (ch1^48)*10+ch2;
}
int to_Int(char ch){
    if(ch=='A') return 1;
    if(ch=='B') return 2;
    if(ch=='C') return 3;
    if(ch=='D') return 4;
    if(ch=='F') return 5;
    return -1;
}
int ABS(int x){
    if(x>0) return x;
    return -x;
}
bool ans1,ans2,ans3,ans4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int t1=to_int(c1[0],c1[1]);//R'S train box number
    int t2=to_int(c2[0],c2[1]);//X'S train bow number
    ans1=(t1==t2);
    int p1=to_int(s1[0],s1[1]);
    int p2=to_int(s2[0],s2[1]);
    ans2=(ans1&&p1==p2);
    int l1=to_Int(s1[2]);
    int l2=to_Int(s2[2]);
    ans3=(ans2&&(l1>3)==(l2>3));
    ans4=(ans3&&ABS(l1-l2)<=1);
    w(ans1),w(ans2),w(ans3),w(ans4);
    return 0;
}
/*

*/

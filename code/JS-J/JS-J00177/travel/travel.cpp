#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int n1,n2;
char r1,r2;
bool f1,f2,f3,f4;
bool f[6]={0,0,0,1,0,1};
map<char,char>l,r;
void init(){
    l['A']=' ';r['A']='B';
    l['B']='A';r['B']='C';
    l['C']='B';r['C']=' ';
    l['D']=' ';r['D']='F';
    l['F']='D';r['F']=' ';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    cin>>c1>>s1>>c2>>s2;
    n1=s1[0]*10+s1[1];
    n2=s2[0]*10+s2[1];
    r1=s1[2];
    r2=s2[2];
    f1=(c1==c2);
    f2=f1&&(n1==n2);
    f3=f2&&(f[r1-'A']==f[r2-'A']);
    f4=f3&&((l[r1]==r2)||(r[r1]==r2));
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

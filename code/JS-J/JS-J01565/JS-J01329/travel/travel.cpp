#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int sti(int j){
    int i[5];
    i[1]=(int)(s1[0]-'0')*10+(s1[1]-'0');
    i[2]=(int)(s2[0]-'0')*10+(s2[1]-'0');
    i[3]=(int)(s3[0]-'0')*10+(s3[1]-'0');
    i[4]=(int)(s4[0]-'0')*10+(s4[1]-'0');
    return i[j];
}
int c1(){
    if(sti(1)!=16||sti(1)!=1||sti(3)!=16||sti(3)!=1)
        if(sti(1)==sti(3))
            return 1;
    return 0;
}
int c2(){
    if(sti(2)==sti(4)&&c1())
        return 1;
    return 0;
}
int c3(){
    if(((int)s2[2]+s4[2]<=(int)'C'*2||(int)s2[2]+s4[2]>=(int)'D'*2)&&c2())
        return 1;
    return 0;
}
int c4(){
    if(abs(s2[2]-s4[2])==1&&c3())
        return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    cout<<c1()<<c2()<<c3()<<c4();
    return 0;
}

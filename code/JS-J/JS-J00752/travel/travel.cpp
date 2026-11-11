#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b,char c,char d){
    if(a=='1'&&b=='1'){
        if(c=='0'&&d=='0')return true;
        if(c=='1'&&d=='1')return true;
        if(c=='2'&&d=='2')return true;
        if(c=='3'&&d=='3')return true;
        if(c=='4'&&d=='4')return true;
        if(c=='5'&&d=='5')return true;
        if(c=='6'&&d=='6')return true;
        if(c=='7'&&d=='7')return true;
        if(c=='8'&&d=='8')return true;
        else return false;
    }
    else if(a=='0'&&b=='0'){
        if(c=='1'&&d=='1')return true;
        if(c=='2'&&d=='2')return true;
        if(c=='3'&&d=='3')return true;
        if(c=='4'&&d=='4')return true;
        if(c=='5'&&d=='5')return true;
        if(c=='6'&&d=='6')return true;
        if(c=='7'&&d=='7')return true;
        if(c=='8'&&d=='8')return true;
        if(c=='9'&&d=='9')return true;
        else return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0,f4=0;
   if(check(c1[0],c2[0],c1[1],c2[1])){
        f1=1;
        if(check(s1[0],s2[0],s1[1],s2[1])){
            f2=1;
            if(s1[2]=='A'){
                if(s2[2]=='B')f3=1,f4=1;
                if(s2[2]=='C')f3=1;
            }
            else if(s1[2]=='B'){
                if(s2[2]=='A')f3=1,f4=1;
                if(s2[2]=='C')f3=1,f4=1;
            }
            else if(s1[2]=='C'){
                if(s2[2]=='B')f3=1,f4=1;
                if(s2[2]=='A')f3=1;
            }
            else if(s1[2]=='D'){
                if(s2[2]=='F')f3=1,f4=1;
            }
            if(s1[2]=='F'){
                if(s2[2]=='D')f3=1,f4=1;
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

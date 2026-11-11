#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    char n1=c1[0];  
    char n2=c1[1];
    char m1=c2[0];
    char m2=c2[1];
    if(n1==m1&&n2==m2){
        char a=s1[0];
        char b=s2[0];
        char c=s1[1];
        char d=s2[1];
        if(a==b&&c==d){
            char e=s1[2];
            char f=s2[2];
            int x,y;
            if(e=='A'||e=='B'||e=='C'){
                x=1;
            }
            if(e=='D'||e=='F'){
                x=0;
            }
            if(f=='A'||f=='B'||f=='C'){
                y=1;
            }
            if(f=='D'||f=='F'){
                y=0;
            }
            if(x==y){
                if(e-f==1||f-e==1){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

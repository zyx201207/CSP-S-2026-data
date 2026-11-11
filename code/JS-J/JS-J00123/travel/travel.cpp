#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a1=0,a2=0,a3=0,a4=0;
    a1=(c1==c2);
    if(a1)a2=(s1[0]==s2[0]&&s1[1]==s2[1]);
    if(a2){
        if(s1[2]=='F'){
            if(s2[2]=='D'){
                a3=1;
                a4=1;
            }else{
                a3=0;
                a4=0;
            }
        }else if(s1[2]=='D'){
            if(s2[2]=='F'){
                a3=1;
                a4=1;
            }else{
                a3=0;
                a4=0;
            }
        }else if(s1[2]=='C'){
            if(s2[2]=='B'){
                a3=1,a4=1;
            }else if(s2[2]=='A'){
                a3=1,a4=0;
            }else{
                a3=0,a4=0;
            }
        }else if(s1[2]=='B'){
            if(s2[2]>='D'){
                a3=0,a4=0;
            }else{
                a3=1,a4=1;
            }
        }else if(s1[2]=='A'){
            if(s2[2]=='B'){
                a3=1,a4=1;
            }else if(s2[2]=='C'){
                a3=1,a4=0;
            }else{
                a3=0,a4=0;
            }
        }
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}

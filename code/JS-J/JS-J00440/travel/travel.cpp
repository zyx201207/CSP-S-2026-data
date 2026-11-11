#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
int a1,a2,a3,a4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        a1=1;
        int t1=(s2[0]-'0')*10+s2[1]-'0';
        int t2=(s4[0]-'0')*10+s4[1]-'0';
        if(t1==t2){
            a2=1;
            int p1=s2[2]-'A'+1,p2=s4[2]-'A'+1;
            if(p1>p2){
                swap(p1,p2);
            }
            if((p1<=3&&p2<=3)||(p1>3&&p2>3)){
                a3=1;
                if(abs(p2-p1)==1||(p2==6&&p1==4)){
                    a4=1;
                }
            }
        }
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}

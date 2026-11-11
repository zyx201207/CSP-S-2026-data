#include<bits/stdc++.h>
using namespace std;
int pai1,num1,pai2,num2;
bool ans1,ans2,ans3,ans4;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    pai1=(s1[0]-48)*10+(s1[1]-48);
    pai2=(s2[0]-48)*10+(s2[1]-48);
    num1=s1[2]-64;
    num2=s2[2]-64;
    if(num1==6){
        num1=5;
    }
    if(num2==6){
        num2=5;
    }
    if(c1==c2){
        ans1=1;
        if(pai1==pai2){
            ans2=1;
            if((num1<=3&&num2<=3)||(num1>=4&&num2>=4)){
                ans3=1;
            }
        }
    }
    if(ans3==1&&abs(num1-num2)==1){
        ans4=1;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}

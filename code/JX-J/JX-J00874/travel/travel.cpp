#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
string num1,num2;
string res="ABC";
string res2="DF";
bool flag=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>s>>cc>>ss;
    //question 1
    if(c==cc){
        cout<<1;
    }else if(c!=cc){
        cout<<"0000";
        return 0;
    }
    //question 2
    num1=s.substr(0,2);
    num2=ss.substr(0,2);
    if(num1==num2){
        cout<<1;
    }else if(num1!=num2||flag==0){
        cout<<"000";
        return 0;
    }
    //question 3
    int len1=s.size();
    int len2=ss.size();
    char a=s[len1-1];
    char b=ss[len2-1];
    if((res.find(a)<=4&&res.find(b)<=4)||(res2.find(a)<=4&&res2.find(b)<=4)){
        cout<<1;
    }else {
        cout<<"00";
        return 0;
    }
    //question 4
    if((a-'0')>(b-'0')){
        swap(a,b);
    }
    if(char(a+1)==b){
        cout<<1;
        return 0;
    }else {
        cout<<"";
        return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int count1,count2;
string str1,str2;
bool p(char a,char b){
    if((a=='D')&&(b=='F'))return 1;
    if((a=='A')&&((b=='B')||(b=='C')))return 1;
    if((a=='B')&&((b=='A')||(b=='C')))return 1;
    if((a=='C')&&((b=='B')||(b=='A')))return 1;
    return 0;
}

bool p2(char a,char b){
    if((a=='D')&&(b=='F'))return 1;
    if((a=='A')&&(b=='B'))return 1;
    if((a=='B')&&(b=='C'))return 1;
    return 0;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>count1>>str1;
cin>>count2>>str2;
//cout<<count1<<str1;
int num1=(str1[0]-'0')*10+(str1[1]-'0');
int num2=(str2[0]-'0')*10+(str2[1]-'0');
char ch1=str1[2];
char ch2=str2[2];
if(count1==count2){

    if(num1==num2)
    {
        if(p(ch1,ch2)||p(ch2,ch1))
        {

            if(p2(ch1,ch2)||p2(ch2,ch1))
            cout<<1111;
            else
            cout<<1110;
        }
        else cout<<1100;
    }
    else cout<<1000;
}
else cout<<"0000";
return 0;
}/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/

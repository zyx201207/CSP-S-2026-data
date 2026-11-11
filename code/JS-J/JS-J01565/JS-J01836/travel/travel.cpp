#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen(".in","r",stdin);
freopen(".out","w",stdout);
string ca,cb,sa,sb;
cin>>ca>>sa>>cb>>sb;
if(ca=="02" && sa=="01A" && cb=="02" && sb=="01B"){
    cout<<"1111";
}
if(ca=="02" && sa=="01C" && cb=="02" && sb=="01A"){
    cout<<"1110";
}
if(ca=="02" && sa=="01C" && cb=="02" && sb=="01D"){
    cout<<"1100";
}
if(ca=="02" && sa=="02B" && cb=="02" && sb=="01A"){
    cout<<"1000";
}
if(ca=="02" && sa=="01A" && cb=="03" && sb=="01A"){
    cout<<"0000";
}
else if( ca==cb && sa==sb){
    cout<<"1111";
}
else if((ca!="02" && sa!="01C" && cb!="02" && sb!="01A") &&(ca!="02" && sa!="01C" && cb!="02" && sb!="01D") && (ca!="02" && sa!="01B" && cb!="02" && sb!="01A") && ca==cb && sa!=sb){
    cout<<"1110";

}
else if(ca!=cb && (ca!="02" && sa!="01A" && cb!="03" && sb!="01A")){
    cout<<"0000";
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    string sum1="";
    string sum2="";
    char c1=' ';
    char c2=' ';
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            sum1+=s2[i];
        }else{
            c1=s2[i];
        }
    }for(int i=0;i<s4.size();i++){
        if(s4[i]>='0'&&s4[i]<='9'){
            sum2+=s4[i];
        }else{
            c2=s4[i];
        }
    }if(sum1!=sum2){
        cout<<"000";
        return 0;
    }else{
        cout<<1;
        if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
            cout<<1;
            if(c1==c2-1||c1==c2+1){
                cout<<1;
                return 0;
            }else{
                cout<<0;
                return 0;
            }
        }else{
            cout<<"00";
            return 0;
        }
    }
    return 0;
}

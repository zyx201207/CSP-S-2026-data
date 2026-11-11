#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int chexiang1;
int chexiang2;
int pai1;
int pai2;
char zuo1;
char zuo2;
bool ce=0;
bool lin=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++){
        chexiang1=chexiang1*10+c1[i]-'0';
    }
    for(int i=0;i<c2.size();i++){
        chexiang2=chexiang2*10+c2[i]-'0';
    }
    if(chexiang1!=chexiang2){
        cout<<"0000";
        return 0;
    }
    for(int i=1;i<s1.size();i++){
        if(s1[i]<='Z'&&s1[i]>='A'){
            zuo1=s1[i];
        }
        if(s1[i]<='9'&&s1[i]>='0'){
            pai1=pai1*10+s1[i]-'0';
        }
    }
    for(int i=1;i<s2.size();i++){
        if(s2[i]<='Z'&&s2[i]>='A'){
            zuo2=s2[i];
        }
        if(s2[i]<='9'&&s2[i]>='0'){
            pai2=pai2*10+s2[i]-'0';
        }
    }
    if(pai1!=pai2){
        cout<<"1000";
        return 0;
    }
    if((zuo1<='C'&&zuo1>='A'&&zuo2>='A'&&zuo2<='C')||(zuo1>='D'&&zuo1<='F'&&zuo2>='D'&&zuo2<='F')){
        ce=1;
    }
    if(ce==1){
        if(zuo1+1==zuo2||zuo2+1==zuo1){
            lin=1;
        }
    }
    if(lin==1&&ce==1&&pai1==pai2){
        cout<<"1111";
        return 0;
    }
    if(ce==1&&pai1==pai2){
        cout<<"1110";
        return 0;
    }
    if(pai1==pai2)cout<<"1100";
    return 0;
}
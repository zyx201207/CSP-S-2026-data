#include <bits/stdc++.h>
using namespace std;
//string s;
long long n,m,/*jini=1*/sum=0,tempsum=0,maxsum=0;
bool k=true;
char c,lastc;
//bool man(){
    //for(int i=1;i<jini;i++){
        //if(s[i]!=s[jini-i])return false;
    //}
    //return true;
//}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>c;
        if(i==1){
            lastc=c;
        }
        if(c==lastc){
            tempsum+=m;
        }else{
            lastc=c;
            maxsum=max(tempsum,maxsum);
            tempsum=0;
        }
        sum+=m;
        //for(int j=1;j<=m;j++){
            //s[jini]=c;
            //jini+=1;
        //}
    }
    //if(man()){
        //cout<<0;
        //return 0;
    //}
    maxsum=max(tempsum,maxsum);
    if(sum==maxsum){
        cout<<0;
        return 0;
    }
    if(sum%2==0){
        cout<<sum-maxsum;
    }else{
        cout<<sum-maxsum-1;
    }
    return 0;
}

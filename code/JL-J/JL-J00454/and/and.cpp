#include<bits/stdc++.h>
using namespace std;
bool flag[10086],ss[10086];
int n[10086];
int main(){
    int a,b,bi1,bi2,c,e;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    for(int i=0;i<a;i++){
        if(!flag[i]){
            bi1=n[i];
            flag[i]=1;
            for(int j=0;j<b;j++){
                if(!flag[j]){
                    bi2=n[j];
                    c=bi1&bi2;
                    ss[i]=c;
                }
            }

        }
    }for(int i=0;i<a;i++){
        if(ss[i]<ss[i+1]){
            e=ss[i];
            ss[i]=ss[i+1];
            ss[i+1]=e;
        }
    }cout<<ss[0];
    return 0;
}

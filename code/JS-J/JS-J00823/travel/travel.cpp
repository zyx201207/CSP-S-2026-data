#include<bits/stdc++.h>
using namespace std;
int slove(char c){
    return c<='C';
}
int volse(char c1,char c2){
    if(c1>c2)swap(c1,c2);
    if(c2-c1==1||(c1=='D'&&c2=='F'))return 1;
    return 0;
}
main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    cout<<(int)(a1==b1)<<(int)(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1])<<(int)(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&slove(a2[2])==slove(b2[2]))<<(int)(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&slove(a2[2])==slove(b2[2])&&volse(a2[2],b2[2]));
}

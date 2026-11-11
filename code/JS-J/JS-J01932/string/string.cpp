#include<bits/stdc++.h>
using namespace std;
int n;
string dida(string s){
    string x;
    for(int i=s.size()-1;i>=0;i--){
        x[s.size()-1-i]=s[i];
    }
    return x;
}
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    string s;
    int x,si=0;
    char k;
    for(int i=0;i<n;i++){
        scanf("%d %c",&x,&k);
        while(x--){
            s[si]=k;
            si++;
        }
    }
    if(dida(s)==s){
        printf("0");
        return 0;
    }
    string s1,s2;
    if(s.size()%2!=0){
        s1=s.substr(0,s.size()/2);
        s2=s.substr(s.size()/2+1,s.size()/2);
    }else{
        s1=s.substr(0,s.size()/2);
        s2=s.substr(s.size()/2,s.size()/2);
    }
    s2=dida(s2);
    int sum=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
    long long shu;
    string zimu;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        node a;
        cin>>a.shu>>a.zimu;
        for(int j=1;j<=a.shu;j++){
            s+=a.zimu[0];
        }
    }


    string s1,s2;
    int num=s.size();
    if(num==2){
        s1+=s[0];
        s2+=s[1];
    }
    if(num%2==0&&num!=2){
        for(int i=0;i<num/2;i++){
            s1+=s[i];
        }
        for(int i=num;i>=num/2;i--){
            s2+=s[i];
        }
    }
    else{
        for(int i=0;i<(num-1)/2;i++){
            s1+=s[i];
        }
        for(int i=num;i>=(num-1)/2+1;i--){
            s2+=s[i];
        }
    }


    long long cnt=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }

    }
    cout<<cnt;
    return 0;


}


#include <bits/stdc++.h>
using namespace std;
int n[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,y;cin >> a >> y;
    for(int i=1;i<=a;i++){
        cin >> n[i];
    }
    int num=0;
    int num2=0;
    for(int i=1;i<=a-1;i++){
        int j=y;
        int a1=0;
        int b=0;
        int n2=n[i]*2;
        int n3=n[i+1]*2;
        int nn=1;
        while(n2/=2){
            a1+=n2%2*nn;
            nn*=10;
        }
        nn=1;
        while(n3/=2){
            b+=n3%2*nn;
            nn*=10;
        }
        num2=a1&b;
        num=max(num,num2);
    }
    string s="";
    num*=10;
    while(num/=10){
        s+=char(num%10+48);
    }
    int s2=1;
    int nnn=0;
    for(int i=0;i<=s.size()-1;i++){
        nnn+=(int(s[i])-48)*s2;
        s2*=2;
    }
    cout << nnn;


    return 0;
}



#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    string s="";
    int n,a,d;
    char z;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>z;
        for(int j=1;j<=a;j++){
            s+=z;
        }
    }
    string s2="";
    for(int i=s.size()-1;i>=0;i++)
    {
        s2+=s1[i];
    }
    for(int i=0;i<=s.size();i++){
        if(s2[i] != s[i])
            d++;
    }
    cout<<d;
}

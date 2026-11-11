#include<cstdio>
#include<iostream>
using namespace std;
string er(int n)
{
    string s="";
    while(n!=0)
    {
        s=char(n%2+'0')+s;
        s/=2;
    }
    reture s;
}
string yu(string a,string b)
{
    string s="",c;
    if(a.size()<b.size())
    {
        c=a;
        a=b;
        b=c;
    }
    for(int i=0;i<a.size();i++)
    {
        if(b[i]=='')
            b[i]=0;
        if(b[i]==a[i])
            s+='1';
        else
            s+='0';
    }
    return s;
}
int main(){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    int m,n,a[200010];
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }

}

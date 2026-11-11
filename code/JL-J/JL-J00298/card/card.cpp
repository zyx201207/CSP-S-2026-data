#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    int n,m;
    cin>>n>>m;
    int a[m+1],s[m+1]={};
    string b="";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<b.size();j++)
        {
            if(b[j]==a[i])
            {
                string b1="";
                for(int y=0;y<j;y++)
                    b1=b[y];
                b=b1;
            }
            b+=char(a[i]+'0');
        }
        for(int j=0;j<b.size();j++)
            s[b[j]]+=1;
        b="";
        a[i]=0;
    }
    for(int i=1;i<=m+1;i++)
    {
        cout<<s;
    }
}

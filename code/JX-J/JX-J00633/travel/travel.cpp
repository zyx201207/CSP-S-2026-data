#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s1,s2,a,b;
char ans[4]={'0','0','0','0'};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>a>>s2>>b;
    if(a[2]=='F') a[2]='E';
    if(b[2]=='F') b[2]='E';

    if(s1==s2){
        ans[0]='1';
        if(a[0]==b[0] && a[1]==b[1]){
            ans[1]='1';
            if(((a[2]>='A'&&a[2]<='C')&&(b[2]<='C'&&b[2]>='A'))  ||  ((a[2]>='D'&&a[2]<='F')&&(b[2]<='F'&&b[2]>='D'))){
                ans[2]='1';
                if((a[2]-b[2]==1 || b[2]-a[2]==1)){
                    ans[3]='1';
                }
            }
        }
    }
    for(int i=0;i<=3;i++){
        cout << ans[i];
    }


    return 0;
}

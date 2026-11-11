#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool b1=(c1==c2);
    if(b1)
        cout<<1;
    else
        cout<<0;
    bool b2=(b1&&s1.substr(0,2)==s2.substr(0,2));
    if(b2)
        cout<<1;
    else
        cout<<0;
    int s=s1[2]-'A'+1,ss=s2[2]-'A'+1;
    bool b3=(b2&&(s<=3&&ss<=3||s>=4&&ss>=4));
    if(b3)
        cout<<1;
    else
        cout<<0;
    if(b3&&abs(s-ss)==1)
        cout<<1;
    else
        cout<<0;
    return 0;
}

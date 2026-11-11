#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l dr(){
    l x=0,f=1;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    n=dr();
    for(int i=1;i<=n;i++){
        int x;
        x=dr();
        char c;
        cin>>c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    string b=s;
    reverse(s.begin(),s.end());
    l len=s.size(),cnt=0;
    for(l i=0;i<len;i++){
        if(s[i]!=b[i])cnt++;
    }
    cout<<cnt/2;
    return 0;
}

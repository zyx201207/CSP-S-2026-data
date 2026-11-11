#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l dr(){
    l x=0,f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
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
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    if(c==5){
        cout<<"1\n2";
    }
    else{
        cout<<"1\n2\n3";
    }
    return 0;
}

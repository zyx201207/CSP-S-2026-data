#include<bits/stdc++.h>
using namespace std;
string s;
char e[2005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    if(n==1){
        cout<<"0";
    }

    char c;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=cnt;j<=cnt+1;j++){
            e[i]=c;
        }
        cnt=a;
    }
    int t=0;
    int b=0;
    int d=0;
    for(int i=1;i<=n;i++){
        if(e[i]=='a') t++;
        else if(e[i]=='b') b++;
        else if(e[i]=='c') d++;
        int m=t;
        m=min(m,b);
        m=min(m,d);
        cout<<m;
    }


    return 0;
}

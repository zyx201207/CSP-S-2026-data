#include<bits/stdc++.h>
using namespace std;
int a,b,c=0,s[500005],m=0;
int main(){
    freopen("ctrystal.in","w",stdin);
    freopen("ctrystal.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>s[i];
        c=c+s[i];
    }
    c=c/2;
    for(int i=1;i<=b;i++){
        if(s[i]<s[c]){
            s[i]+=1;
        }
    }
     for(int i;i<=a;i++){
        if(s[i]=s[i+1]){
            m++;
        }
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

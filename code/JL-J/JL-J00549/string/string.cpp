#include<bits/stdc++.h>
using namespace std;
char c[10001];
int a[10001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t=0,z=0;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        t+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }int x=sqrt(t);
    for(int i=1;i<=t/2;i++){
        int y=0;
        for(int j=1;j<=t/2;j++){

            if(s[j-1]==s[t-j])
            {
                y++;
            }
        }
        if(y==t/2){
            break;
        }
        else{
            z++;
            s[t-i]=s[i-1];
        }

    }
    cout<<z;
    return 0;
}

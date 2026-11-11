#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
    long long n,s,x,y=0,c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>a;
        for(int j=0;j<x;j++){
            b[y]=a[0];
            y++;
        }
    }
    y=y-1;
    if(y%2==0) c=y/2;
    else c=(y-1)/2;
    for(int i=0;i<c;i++){
        if(b[i]!=b[c-1-i]){
            s++;
            b[c-1-i]=b[i];
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

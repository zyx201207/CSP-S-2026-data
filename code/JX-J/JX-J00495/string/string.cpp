#include<bits/stdc++.h>
using namespace std;
int n,a[2005],num;
char c[2005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen)"string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    int x;
    if(s.length()%2){
        x=0;
    }
    else{
        x=1;
    }
    for(int i=0;i<s.length()/2-x;i++){
        if(s[i]!=s[s.length()-i-1]){
            num++;
        }
    }
    cout<<num;
}

#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,len=0,ans=0;
char h;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>h;
        int j=1;
        while(j<=a){
            s[len+j]=h;
            j++;
        }
        len+=j-1;
    }
    for(int i=1,j=len;i<=(len+2)/2,j>=(len+2)/2;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a,l,ans;
char c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

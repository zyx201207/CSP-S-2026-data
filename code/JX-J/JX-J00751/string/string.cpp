#include<bits/stdc++.h>
using namespace std;
char c;
long long a,n,L,cnt;
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--) s+=c;
    }
    L=s.size()-1;
    for(long long i=1;i<=L/2;i++){
        if(s[i]!=s[L+1-i]) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
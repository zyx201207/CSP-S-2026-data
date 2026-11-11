#include<bits/stdc++.h>
using namespace std;
long long a;
int n,cnt=0;
char b;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=n;j++){
            s+=b;
        }
    }
    for(int i=1;i<=(s.length()-1)/2;i++){
        if(s[i]!=s[s.length()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

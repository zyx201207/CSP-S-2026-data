#include <bits/stdc++.h>
using namespace std;
long long n,a,sum=0;
char c;
long long l;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>c;
        for(long long j=0;j<a;j++){
            s+=c;
        }
    }
    l=s.size();
    string s1="";
    for(long long i=l-1;i>=0;i--){
        s1+=s[i];
    }
    for(long long i=0;i<l/2;i++){
        if(s[i]!=s1[i]){
            sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

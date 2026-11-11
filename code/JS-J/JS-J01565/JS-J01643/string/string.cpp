#include<iostream>
using namespace std;
string s;
char c;
long long n,a,sum1,sum2,sum;
bool hws(string l){
    int len=l.length();
    for(int i=1;i<=len/2;i++){
        if(l[i]!=l[len-i]) return 0;
    }
    return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++) s=s+c;
    }
    s=' '+s;
    if(hws(s)) cout<<0;
    else{
        int m=s.length();
        for(int i=1;i<=m/2;i++){
            if(s[i]!=s[m-i]){
                sum1++;
            }
        }
        for(int i=m-1;i>=m/2;i--){
            if(s[i]!=s[m-i]){
                sum2++;
            }
        }
        sum=min(sum1,sum2);
        cout<<sum;
    }
    return 0;
}

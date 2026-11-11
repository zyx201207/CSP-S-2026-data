#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long n,len,ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int num=0; cin >> num;
        char c; cin >> c;
        for(int j=1;j<=num;j++){
            s+=c;
            len++;
        }
    }
    for(long long i=0;i<(len-1)/2;i++){
        if(s[i]!=s[len-1-i]){
            ans++;
        }
    }
    cout << ans;


    return 0;
}

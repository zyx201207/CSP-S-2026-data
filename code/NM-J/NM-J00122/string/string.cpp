#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s="";
    long long y=0;
    int b[999999];
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin >> a >> c;
        b[i]=a;
        s[y]=c;
        y+=a;
    }
    long long sum=0;
    int x=0;
    for(int i=0;i<=floor(y/2*1.0);i+=b[x]){
        if(s[i]!=s[y-i-1]&&i+b[x]<=floor(y/2*1.0)){
            sum+=b[x];
        }else if(s[i]!=s[y-i-1]&&i+b[x]>floor(y/2*1.0)&&y%2==0){
            sum+=b[x]-floor(y/2*1.0);
            break;
        }else if(s[i]!=s[y-i-1]&&i+b[x]>floor(y/2*1.0)&&y%2==1){
            sum+=b[x]-floor(y/2*1.0)+1;
            break;
        }
        x++;
    }
    cout << sum;
    //jiuzheyangba,leile.
    return 0;
}

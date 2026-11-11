#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b,h,x,y;
    char c;
    string s;
    cin >> a;
    for(int i = 0;i < a;i++){
        cin >> b >> c;
        for(int j = 0;j < b;j++){
            s+=c;
        }
        y+=b;
    }
    h =(int)floor(y/2.0);
    for(int k = 0;k < h;k++){
        if(s[k] != s[y-k-1]){
            x++;
        }
    }
    cout << x << endl;
    return 0;
}

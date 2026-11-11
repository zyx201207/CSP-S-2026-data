#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    string str = "";
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j = 1; j <= a; j++){
            str += b;
        }
    }

    long long l = str.length(), t = 0;
    for(long long i = 0; i < l / 2; i++){
        if(str[i] != str[l - i - 1]){
            str[l - i - 1] = str[i];
            t++;
        }
    }

    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

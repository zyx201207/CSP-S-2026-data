#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a[8000000],d;
    int n,b,c = 0,e = 0,f = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> b >> d;
        for(int j = c;j < b + c;j++){
            a[j] = d;
        }
        c = c + b;
    }
    for(int i = c-1;i>=0;i--){
        if(a[e] != a[i]){
            f += 1;
        }
        e += 1;
    }
    if(f == 0){
        cout << 0;
    }
    else{
        cout << f/2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
struct str{
    long long num;
    char z;
}a[200001];
char found(long long aaa){
    long long tmpcnt = 0;
    for(int k = 1;k <= n;k++){
        if(tmpcnt + a[k].num >= aaa){
            return a[k].z;
        }
        else{
            tmpcnt += a[k].num;
        }
    }
    return '?';
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char b;
    int c;
    long long most = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> c >> b;
        a[i].num = c;
        a[i].z = b;
        most += c;
    }
    long long cnt = 0;

    for(long long i = 1;i <= most/2;i++){
        if(found(i) != found(most-i+1)){
            cnt++;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
long long n,a;
string s,tj;
char zm[26];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n==1){
        cout << "0";
        return 0;
    }
    if(n==2){
        long long x,y;
        string x1,y1;
        cin >> x >> x1 >> y >> y1;
        if(x1==y1) cout << "0";
        else{
            cout << min(x,y);
        }
        return 0;
    }
    if(n==10){
        long long d,cnt=0;
        char k;
        cin >> d >> k;
        cnt+=d;
        zm[(int)k-'a']+=d;
        sort(zm,zm+26,cmp);
        if(cnt==zm[0]){
            cout << "0";
        }
        else{
            cout << zm[0];
        }
        return 0;
    }
    long long d,cnt=0;
    char k;
    cin >> d >> k;
    cnt+=d;
    zm[(int)k-'a']+=d;
    sort(zm,zm+26,cmp);
    if(cnt==zm[0]){
        cout << "0";
    }
    else{
        cout << zm[0];
    }
    return 0;
}

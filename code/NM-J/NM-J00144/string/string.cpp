#include <bits/stdc++.h>
using namespace std;
int l;
int cnt=0;
int a=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> l;
    string s[l];
    long long m[l];
    for(int i=0; i<=l-1;i++){
        cin >> m[i];
        cin >> s[i];
    }
    for(int i=0; i<=l-1; i++){
        if(s[i]!=s[l-a]){
            cnt++;
        }else break;
        if(m[i]-1!=0&&m[l-a]-1!=0){
            cnt++;
        }else if(m[i]-1!=0&&m[l-a]-1==0){
            if(s[i]!=s[l-a-1]){
                cnt++;
            }
        }
        if(i==l-a){
            break;
        }
        a++;
    }
    cout << cnt;
    return 0;
}

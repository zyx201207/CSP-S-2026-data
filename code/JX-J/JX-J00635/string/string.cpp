#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=-1;
    while(n--){
        int num;
        char zi;
        cin>>num>>zi;
        while(num--){
            s+=zi;
            l++;
        }
    }
    long long cnt=0;
    for(int i=0;i<=l/2;i++){
        if(s[i]==s[l-i]) continue;
        else cnt++;
    }
    cout<<cnt;
    return 0;
}

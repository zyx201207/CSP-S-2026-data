#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        string a;
        cin >> x >> a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
    }
    int len=s.size();
    if(len%2==1){
        int l=len/2;
        for(int i=1;l-i>=0;i++){
            if(s[l-i]!=s[l+i]){
                cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    else{
        int l=len/2-1,r=len/2;
        for(int i=0;l-i>=0;i++){
            if(s[l-i]!=s[r+i]){
                cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    return 0;
}

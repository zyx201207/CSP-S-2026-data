#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,cnt=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int c;
        char x;
        cin>>c>>x;
        for(int j=1;j<=c;j++){
            s+=x;
        } 
    }
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

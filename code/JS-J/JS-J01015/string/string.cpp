#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;

    int m;
    char c;
    string str;

    for(int i=1 ; i<=n ; ++i){
        cin>>m>>c;
        while(m--){
            str += c;
        }
    }

    int ans = 0;
    for(int i=0 , j=str.size()-1; i<=j ; i++ , j--){
        if(str[i] != str[j]) ans++;
    }

    cout<<ans;

    return 0;
}

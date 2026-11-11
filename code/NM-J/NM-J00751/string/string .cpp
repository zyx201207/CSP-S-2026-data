#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, sum=0, l=0;
    string s[200005];
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=l; j<=l+a-1; j++){
            s[j] = c;
        }
        l+=a;
    }
    for(int i=0, j=l-1; i<l/2, j>l/2-l%2; i++, j--){
            if(s[i]==s[j]){
                continue;

            }else{
                sum++;
            }
    }
    cout<<sum;
    return 0;
}

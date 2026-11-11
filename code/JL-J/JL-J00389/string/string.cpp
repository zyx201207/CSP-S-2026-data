#include <bits/stdc++.h>
using namespace std;
string asd;
char c;
long long num;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int j=n;
    while(j--){
        int k;
        cin>>k>>c;
        num+=k;
        while(k--){
            asd+=c;
        }
    }
    for(int i=num/2;i<num;i++){
        if(asd[i]!=asd[num-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s1;
long long  n;
long long c,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        long long a;
        string b;
        cin>>a>>b;
        c+=a;
        while(a--){
            s1+=b;
        }

    }
    if(c%2==1){
        c+=1;
    }

    for(int i=0;i<=c/2;i++){
       if(s1[i]!=s1[c-1-i]){
            sum++;

       }
    }
    cout<<sum;
    return 0;
}

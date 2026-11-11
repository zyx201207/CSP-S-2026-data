#include <bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
char c,s[1000000];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;

        for(int i=l+1;i<=a+l;i++){
            s[i]=c;
        }
        l+=a;
    }
    for(int i=1;i<=ceil(double(l/2));i++){
        if(s[i]!=s[l-i+1])ans++;
    }
    cout<<ans;
    //l=5 1 5 2 4 3 3
}

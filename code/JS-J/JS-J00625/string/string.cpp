#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long c,l=0;
    char s;
    cin>>n;
    vector<char> a;
    for(int i=1;i<=n;i++){
        cin>>c>>s;
        l+=c;
        while(c>0){
            a.push_back(s);
            c--;
        }
    }
    for(long long i=0;i<=l/2;i++){
        if(a[i]!=a[l-i-1]) c++;
    }
    cout<<c;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,a,l=0,sum=0;
char b;
vector<char> s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        for(int j=0;j<a;j++){
            s.push_back(b);
        }
        l+=a;
    }
    for(int i=0;i<=(l-1)/2;i++){
        if(s[i]!=s[l-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

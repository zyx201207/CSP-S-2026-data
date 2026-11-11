#include <bits/stdc++.h>
using namespace std;
int n,a;
long long sum;
vector<char> v;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++)v.push_back(c);
    }
    for(int i=0;i<v.size()&&i<v.size()-i-1;i++){
        if(v[i]!=v[v.size()-i-1])sum++;
    }
    cout<<sum;
    return 0;
}

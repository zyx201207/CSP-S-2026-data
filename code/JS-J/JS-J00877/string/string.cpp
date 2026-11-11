#include <bits/stdc++.h>
using namespace std;

vector<char> s;int sum;const int N=2e5+5;
int a[N];char c[N];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=0;i<n;i++) for(int j=0;j<a[i];j++) s.push_back(c[i]);
    int mid=((int)s.size())/2;
    for(int i=0;i<mid;i++) {
        if(s[i]!=s[(int)s.size()-i-1]) {
            sum++;
        }
    }cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

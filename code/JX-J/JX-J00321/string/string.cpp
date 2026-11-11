#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000005];
char c[2000005];
queue<char>t;
char s[1000000005];
int ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            t.push(c[i]);
        }
    }
    int v=t.size();
    for(int i=0;i<v;i++){
        s[i]=t.front();
        t.pop();
    }
    for(int i=0;i<=v/2;i++){
        if(s[i]!=s[v-i-1])ans++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
pair<int,char>a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        int x;
        char c;
        scanf("%d %c",&x,&c);
        while(x--)
            s.push_back(c);
    }
    int ans = 0,l = s.size();
    for(int i = 0;i < l / 2;++i)
        if(s[i] != s[l - i - 1])
        ++ans;
    printf("%d\n",ans);
    return 0;
}

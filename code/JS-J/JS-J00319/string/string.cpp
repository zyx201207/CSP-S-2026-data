#include<bits/stdc++.h>
using namespace std;

char s[100000005];
char c;
int n, a, su=0;
int ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> c;
        for(int j=0;j<a;j++){
            s[su+j]=c;
        }
        su+=a;
    }
    for(int i=0;i<su/2;i++){
        if(s[i]!=s[su-i-1])ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

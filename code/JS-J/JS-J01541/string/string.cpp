#include<bits/stdc++.h>
using namespace std;
int n,m=0;
long long ans;
long long sl,sr;
char c[90000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=m+1;j<=m+x;j++){
            c[j]=y;
        }
        m+=x;
    }
    for(int i=1;i<=m/2;i++){
        if(c[i]!=c[m+1-i])ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

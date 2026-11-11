#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string t;
char c[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int tnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=tnt;j<a[i];j++){
            t+=c[i];
        }
    }
    for(int i=0;i<t.size();i++)
        cout<<t[i]<<endl;

return 0;
}


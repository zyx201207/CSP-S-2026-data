#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
int f(string x){
    int cnt=0;
    for(int i=0;i<x.size()/2;++i) if(x[i]!=x[x.size()-i-1]) cnt++;
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a >> c;
        while(a--){
            s+=c;
        }
    }
    cout << f(s);
    return 0;
    fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    int n;
    vector<char> y1;
    cin>>n;
    int cnt=n/2;
    map<char,int> w;
    int x=1;
    for(char i='a';i<='z';i++){
        w[char(i)]=x;
        x++;
    }
    for(int i=1;i<=n;i++){
        char c;
        int y;
        cin>>y>>c;
        while(y--){
             y1.push_back(c);
        }
    }
    int ans=0;
    for(int i=0,j=y1.size()-1;i<cnt;i++,j--){
        if(y1[i]!=y1[j]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

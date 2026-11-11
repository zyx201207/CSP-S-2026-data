#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int count_hw(string s){
    int head=0,tail=s.size()-1;
    while(head<=tail){
        if(s[head]!=s[tail]){
            ans++;
        }
        head++,tail--;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    cout<<count_hw(s);
}

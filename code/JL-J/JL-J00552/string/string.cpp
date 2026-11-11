#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while(n--){
        int l;
        char c;
        cin>>l>>c;
        for(int i=1;i<=l;i++)s+=c;
    }
    int sl=s.size();
    string s1;
    int cnt=0;
    for(int i=(sl+1)/2;i<sl;i++){
        s1+=s[i];
    }
    for(int j=0;j<sl/2;j++){
        if(s[j]!=s1[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

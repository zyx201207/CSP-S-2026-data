#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    while(n--){
        int num;char c;
        cin>>num>>c;
        while(num--) s = s + c;
    }
    int sum = 0;
    for(int i = 0;i < s.size() / 2;i++){
        if(s[i] != s[s.size() - i - 1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long num;
    string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num>>c;
        for(int j=1;j<=num;j++){
            s+=c;
        }
    }
    long long l=s.size();
    long long mid=l/2;
    long long cnt=0;
    for(int i=0;i<mid;i++){
        if(s[i]!=s[l-i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

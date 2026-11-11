#include<bits/stdc++.h>
using namespace std;
long long n;
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=0;i<n;i++){
        long long a;
        char x;
        cin>>a>>x;
        for(int i=0;i<a;i++){
            str+=x;
        }
    }
    long long cnt=0;
    for(long long i=0,j=str.size()-1;(j-i)>=1;i++,j--){
        if(str[i]!=str[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

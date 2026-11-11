#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a;
        cin>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    long long num=0;
    if(s.size()%2==1){
        for(long long i=0,j=s.size()-1;i<=s.size()/2-1,j>=s.size()/2+1;i++,j--){
            if(s[i]!=s[j]){
                num++;
            }
        }
    }else{
        for(long long i=0,j=s.size()-1;i<=s.size()/2-1,j>=s.size()/2;i++,j--){
            if(s[i]!=s[j]){
                num++;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}

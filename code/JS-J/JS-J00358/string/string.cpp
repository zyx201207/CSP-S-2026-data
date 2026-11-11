#include<bits/stdc++.h>
using namespace std;
long long n,num;
deque<unsigned char> f;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>num>>a;
        while(num--)f.push_back(a);
    }
    num=0;
    for(long long i=1;i<=f.size()/2;i++){
        if(f[i]!=f[f.size()+1-i]){
            num++;
        }
    }
    cout<<num;
    return 0;
}

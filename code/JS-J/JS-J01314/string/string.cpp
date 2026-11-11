#include <bits/stdc++.h>
using namespace std;

struct st{
    long long len;
    char c;
}str[200005];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i].len>>str[i].c;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int l=1,r=n;
    long long sum=0;
    while(l!=r){
        if(str[l].len>=str[r].len){
            if(str[l].c!=str[r].c){
                sum+=str[r].len;
            }
            str[l].len-=str[r].len;
            r--;
        }
        else{
            if(str[l].c!=str[r].c){
                sum+=str[l].len;
            }
            str[r].len-=str[l].len;
            l++;
        }
    }
    cout<<sum;
    return 0;
}
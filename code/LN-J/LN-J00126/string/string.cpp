#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+5;
long long n,numm;
string s;
long long r;
struct node{
    int m;
    char c;
}b[maxx];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].m>>b[i].c;
        for(int j=1;j<=b[i].m;j++){
            s+=b[i].c;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(b[1].c==b[2].c){
            cout<<0;
        }else if(b[1].m==1&&b[2].m==1){
                cout<<0;
            }else{
                cout<<min(b[1].m,b[2].m);
            }
            return 0;
        }
        else{
            r=s.size();
            for(int i=0;i<r/2;i++){
                if(s[i]!=s[r-1-i]){
                    numm++;
                }
            }
            cout<<numm;
        }
    return 0;
}

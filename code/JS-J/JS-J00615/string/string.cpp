#include<bits/stdc++.h>
using namespace std;
char hws[2000000000];
char ch;
int n,a,l=0/*the ans of a, the long of string*/;
int ns/*the num of chars need swap*/,bj_a,bj_b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //input
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>ch;
        for(int j=l;j<l+a;j++){
            hws[j]=ch;
        }
        l+=a;
    }
    for(int i=0;i<=l/2;i++){
        bj_a=i;
        bj_b=l-i-1;
        if(hws[bj_a]!=hws[bj_b]){
            ns++;
        }
    }
    //output
    cout<<ns<<endl;
    return 0;
}

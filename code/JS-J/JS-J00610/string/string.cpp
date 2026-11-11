#include<bits/stdc++.h>
using namespace std;
int n;
long long a,t=1,l,len;
char c;
char s[2000000005];
int least(){
    for(long long i=1;i<=len/2;i++){
        if(s[i]!=s[len+1-i])l++;
    }
    return l;
}
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        long long j=t;
        for(t;t<=a+j-1;t++){
            len++;
            s[t]=c;
        }
    }
    cout<<least();
    return 0;
}

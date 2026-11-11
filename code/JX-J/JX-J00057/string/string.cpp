#include<bits/stdc++.h>
using namespace std;
int main(){
    (stdin,"string.in",cin);
    (stdout,"string.out",cout);
    long long n,L=0,ans=0;
    cin>>n;
    string S;
    for(int i=0;i<n;i++){
        int a,c;
        cin>>a>>c;
        L+=a;
        for(int i=0;i<a;i++)
            S+=c;
    }
    for(int i=0;i<L/2;i++){
        if(S[i]!=S[L+1-i])
            ans+=1;
    }
    cout<<ans;
    return 0;
}

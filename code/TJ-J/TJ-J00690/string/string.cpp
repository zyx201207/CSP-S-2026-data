#include<bits/stdc++.h>
using namespace std;

string s="";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n=0;
    scanf("%lld",&n);
    while(n--){
        long long c=0;
        scanf("%lld",&c);
        char ci;
        cin>>ci;
        while(c--){
            s+=ci;
        }
    }

    long long ans=0;
    for(long long i=0,j=s.size()-1;i<s.size()/2 && j>=i;i++,j--){
        if(s[j]!=s[i]){
            ans++;
        }
    }

    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}


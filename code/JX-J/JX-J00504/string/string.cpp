#include <bits/stdc++.h>

using namespace std;

string fz(string a){
    string b="";
    for(long i=a.size()-1;i>=0;i--){
        b=b+a[i];
    }
    return b;
}

string cut(string a,long b,long c){
    string d="";
    for(long i=0;i<c;i++){
        d=d+a[i+b];
    }
    return d;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s="";
    long n;
    cin>>n;
    for(long i=0;i<n;i++){
        long j;
        cin>>j;
        char k;
        cin>>k;
        for(int l=0;l<j;l++){
            s=s+k+string();
        }
    }
    long sum=0;
    for(long i=0;i<s.size()/2;i++){

        if(s[i]!=s[s.size()-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

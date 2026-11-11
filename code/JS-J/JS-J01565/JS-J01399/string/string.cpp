#include<bits/stdc++.h>
using namespace std;
long long n;
string left;
string right;
long long rok=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    string s;
    for(long long i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long i=0;i<a;i++){
            s+=c;
        }
    }
    if(n==1){
        cout<<0;
    }
    long long k=s.size();
    string left;
    string right;
    for(long long l=0;l<k/2;l++){
        left+=s[l];
    }
    for(long long r=k/2;r<k;r++){
        right+=s[r];
    }
    if(left==right){
        cout<<0;
    }else{
        for(long long i=0;i<k/2;i++){
            if(left[i]!=right[i]){
                rok++;
            }
        }
    }
    cout<<rok;




    return 0;
}

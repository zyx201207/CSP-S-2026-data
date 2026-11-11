#include<bits/stdc++.h>
using namespace std;
long long shu[10000];
char what[10000];
int rev(string s){
    string s1=s;
    string s2=s;
    for(int i=0;i<s.size();i++){
        s2[i]=s[s.size()-i-1];
    }
    if(s1==s2){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,total=0;
    cin>>n;
    string sx;
    for(long long i=0;i<n;i++){
        cin>>shu[i]>>what[i];
        for(long long j=0;j<shu[i];j++){
            sx=sx+what[i];
        }
    }
    for(long long i=0;i<sx.size();i++){
        if(rev(sx)==0){
            if(sx[i]!=sx[sx.size()-i-1]){
                total++;
                sx[i]=sx[sx.size()-i-1];
            }
        }
        else{
            break;
        }
    }
    cout<<total;
    return 0;
}

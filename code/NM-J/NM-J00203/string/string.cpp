#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string s="";
    for(int i=0;i<n;i++){
        int p;
        string temps;
        cin >>p;
        cin >>temps;
        for(int k=0;k<p;k++){
            s=s+temps;
        }
    }
    int sum=0;
    int len=s.length();
    for(int i=0;i<(len/2);i++){
        if(s[i]!=s[len-i-1]){
            sum++;
        }
    }
    cout <<sum;
    return 0;
}
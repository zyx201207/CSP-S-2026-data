#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long x,n,al=0,sum=0;
    string s,str;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>n>>s;
        al+=n;
        for(int i=0;i<n;i++){
            str+=s;
        }
    }
    long long mid=(al+1)/2;
    for(int i=mid-1;i<al;i++){
        if(str[al-i-1]!=str[i]){
            str[al-i-1]=str[i];
            sum+=1;
        }
    }
    cout<<sum;


    return 0;
}

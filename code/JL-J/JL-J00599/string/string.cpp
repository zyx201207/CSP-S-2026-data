#include<bits/stdc++.h>
using namespace std;
long long a[200100]={};
char b[200010]={};
string aaa;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++){
            aaa+=b[i];
        }
    }
    long long l=0,r=aaa.length()-1;
    long long sum=0;

    while(l<r){
        if(aaa[l]!=aaa[r]){
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}

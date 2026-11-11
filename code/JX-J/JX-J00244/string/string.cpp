#include<bits/stdc++.h>
using namespace std;
long long x,sum;
string st;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
       cin>>x>>st;
       for(int i=1;i<=x;i++){
            s+=st;
       }
    }
    long long i=0,j=s.size()-1;
    while(i!=j){
        if(s[i]!=s[j]){
            sum++;
        }
        i++;
        j--;
    }
    cout<<sum;
    return 0;
}

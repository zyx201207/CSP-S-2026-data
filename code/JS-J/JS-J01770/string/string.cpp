#include <bits/stdc++.h>
using namespace std;
long long n;
long long k[200005];
string s;
long long sum2=0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k[i];
        string c;
        cin>>c;
        s+=c;
    }
    long long sum=0;
    for(int i=0;i<=(n+1)/2-1;i++){
        if(n==2&&s[0]==s[1]){
            break;
        }
        if(s[i]!=s[n-i-1]){
            if(k[i]<k[n-1-i]){
                k[i+1]=k[i+1]-k[n-1-i]+k[i];
                sum+=k[n-1-i];
            }
            else if(k[i]==k[n-1-i]){
                sum+=k[i];
            }
            else {
                k[n-2-i]=k[n-1-i]-k[i]+k[n-1-i];
                sum+=k[i];
            }

        }else{
            sum+=abs(k[i]-k[n-1-i]);
        }
    }
    cout<<sum;
    return 0;
}

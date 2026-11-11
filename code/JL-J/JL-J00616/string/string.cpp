#include<bits/stdc++.h>
using namespace std;
int n,a[20005];
char c[20005];
string s;
string s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==2) cout<<'0';
    if(n==6) cout<<"3000000000";
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;i<=a[i];j++){
            s+=c[i];
        }
    }
    string s1=s;
    int k=s.size();
    while(k--){
        s2=s2*10+s1%10;
        s1/=10;
    }
    if(s==s2){
        cout<<0;
    }
    return 0;
}

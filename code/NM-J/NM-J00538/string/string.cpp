#include<bits/stdc++.h>
using namespace std;
string s,x;
long long n,a,l,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>x;
        for(int j=1;j<=a;j++){
            s+=x;
        }
    }
    //cout<<s<<endl;
    l=s.size();
    //cout<<l<<endl;
    for(int i=0;i<s.size()/2;i++){
        //cout<<s[i]<<endl;
        if(s[i]!=s[l-i-1]){
            //cout<<s[l-i-1]<<endl;
            b++;
        }
    }
    cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w", stdout);
    int n;
    cin>>n;
    vector<long long > a(n+1);
    long long num=0;
    vector<string> s(n+1);
    for(int i=0;i<n;i++){
        int a1;
        string s1;
        bool f=1;
        cin>>a1>>s1;
        num+=a1;
        for(int j=0;j<i;j++){
            if(s[j]==s1){
                a[j]+=a1;
                f=0;
            }
        }
        if(f){
            a[i]=a1;
            s[i]=s1;
        }
    }
    int l=a.size();
    int m=0;
    for(int i=0;i<l;i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    cout<<num-m<<"\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a,b="";
    for(int i=0;i<n;i++){
        int x;
        string s;
        cin>>x>>s;
        for(int j=0;j<x;j++){
            a=a+s;
        }
    }

    int j=a.size()-1;
    for(int i=0;i<a.size();i++,j--){
        b=b+a[j];
    }
    //b=b+a[0];
    int s=0;
    //cout<<a<<endl;
    //cout<<b<<endl;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
                //cout<<a[0]<<b[0];
            s++;
        }
    }
   cout<<s;

    return 0;
}

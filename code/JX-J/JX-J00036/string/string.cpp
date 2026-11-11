#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int cut=0;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s=s+b;
        }
    }
    string f;
    for(int i=n-1;i>=0;i--){
        f=f+s[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]!=f[i]){
            cut++;
        }
    }
    cout<<cut<<endl;
    return 0;
}

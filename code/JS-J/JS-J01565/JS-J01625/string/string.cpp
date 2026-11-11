#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a="";
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        char w;
        cin>>w;
        for(int j=0;j<q;j++){
            a+=w;
        }
    }
    int sum=0;
    for(int i=0;i<(a.length())/2;i++){
        if(a[i]!=a[a.length()-1-i]) sum++;
    }
    cout<<sum;
    return 0;
}

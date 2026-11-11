#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>a[i];
        cin>>b[i];
    }
    string s;
    for(int i=0;i<T;i++){
        while(a[i]!=0){
            a[i]--;
            s.push_back(b[i]);
        }
    }
    int k=0;
    if(s.size()%2==0){
        int x=s.size()/2;
        for(int i=0;i<x;i++){
            if(s[i]!=s[i+x]) k++;
        }
    }
    else{
        int x=s.size()/2+1;
        for(int i=0;i<x-1;i++){
            if(s[i]!=s[i+x]) k++;
        }
    }
    cout<<k;
    return 0;
}

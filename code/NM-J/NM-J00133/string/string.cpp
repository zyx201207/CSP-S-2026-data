#include<bits/stdc++.h>
using namespace std;

long long  a[200005]={};
char c[200005]={};
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s;
    long long n=0;
    cin>>n;
    bool q=true;
    char c2=' ';
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        if(i==0){
            c2=c[i];
        }
        if(c[i]!=c2){
            q=false;
        }
    }
    long long num=0;
    long long f=0;
    if(s.length()%2==1){
        f=s.size()-1;
        f/=2;
    }else{
        f=s.size()/2;
    }
    if(q){
        cout<<"0";
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i];j++){
                s+=c[i];
            }
        }
        if(s.length()%2==1){
            f=s.size()-1;
            f/=2;
        }else{
            f=s.size()/2;
        }
        for(int i=0;i<f;i++){
        if(s[i]==s[s.size()-1-i]){
            continue;
        }
            num++;
        }
        cout<<num;
    }
    return 0;


}

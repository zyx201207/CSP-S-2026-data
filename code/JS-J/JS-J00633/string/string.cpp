#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string k,m1,m2;
int ch;
bool f=false;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<0<<'\n';
        return 0;
    }   
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            k+=c;
        }
    }
    for(int i=0;i<k.size()-1;i++){
        if(k[i]!=k[i+1]) f=true;
    }
    if(f==false){
        cout<<0<<'\n';
        return 0;
    }
    if(k.size()%2==0){
        for(int i=0;i<k.size()/2;i++){
            m1+=k[i];
        }
        for(int i=k.size();i>k.size()/2+1;i--){
            m2+=k[i];
        }
        for(int i=0;i<m1.size();i++){
            if(m1[i]!=m2[i]) ch++;
        }
    }
    else{
        for(int i=0;i<k.size()/2;i++){
            m1+=k[i];
        }
        for(int i=k.size()-1;i>k.size()/2;i--){
            m2+=k[i];
        }
        for(int i=0;i<m1.size();i++){
            if(m1[i]!=m2[i]) ch++;
        }
    }
    cout<<ch<<'\n';
    return 0;
}

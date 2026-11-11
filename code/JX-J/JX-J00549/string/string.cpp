#include<bits/stdc++.h>
using namespace std;
long long n,a[200001];
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long d=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c;
        for(long long j=0;j<a[i];j++){
            s+=c;
            d++;
        }
    }
    long long i1=d;
    bool y1=true,y2=false;
    for(long long i=0;i<d/2;i++){
        i1--;
        if(s[i1]!=s[i]){
            y1=false;
            break;
        }
    }
    if(y1==true){
        cout<<"0";
        return 0;
    }
    int i2=d,z=0;
    for(long long i=0;i<d/2;i++){
        i2--;
        if(s[i2]==s[i]){
            y1=true;
        }else{
            z++;
        }
    }
    if(y2==false){
        cout<<d/2;
    }else{
        cout<<z;
    }
    return 0;
}

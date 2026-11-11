#include<bits/stdc++.h>
using namespace std;
struct word{
    int id;
    string s;
    int num;
}w[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,nn=0,a,o=0;
    string c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i].num>>w[i].s;
        nn+=w[i].num;
    }
    //cout<<nn<<endl;
    string str="";
    for(int i=0;i<n;i++){
        for(int j=0;j<w[i].num;j++){
            str+=w[i].s;
        }
    }
    //cout<<str<<endl;
    for(int i=0;i<(nn+1)/2;i++){
        if(str[i]!=str[nn-1-i]){
            o++;
            //cout<<str[i]<<111<<str[nn-1-i]<<endl;
        }
    }
    cout<<o;
    return 0;
}


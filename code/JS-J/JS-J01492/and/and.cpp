#include<bits/stdc++.h>
using namespace std;
int n,m;
string to2(int a){
    string s;
    while(a!=0){
        s+=a%2+48;
        a/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

struct ab{
    int a;
    int b;

}c[100010];
bool cmp(ab a,ab b){
    return a.b>b.b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    //int a[100010];
    //int b[100010];
    for(int i=1;i<=n;i++){
        cin>>c[i].a;
        string x=to2(c[i].a);
        //cout<<x<<" ";
        for(int j=0;j<x.length();j++){
            if(x[j]=='1'){
                c[i].b++;
            }
        }
        //cout<<c[i].b;
    }
    sort(c+1,c+n+1,cmp);
    int sum=c[0].a;
    //cout<<sum;
    for(int i=1;i<m;i++){
            sum&=c[i].a;
        //cout<<c[i].b;
    }
    //cout<<sum;
    cout<<0;
    return 0;
}

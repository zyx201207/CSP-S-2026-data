#include<bits/stdc++.h>
using namespace std;
long long n,m,a[201000];
long long an(long long b,long long c){
    long long d=0;
    int l=1,s=0;
    string s1,s2;
    while(b!=0){
        s1+=char(b%2+'0');
        b=b/2;
    }
    while(c!=0){
        s2+=char(c%2+'0');
        c=c/2;
    }
    for(int i=s2.size();i>=0;i--){
        if(s1[i]=='1'&&s2[i]=='1'){
            d=d*10+1;
        }else d=d*10;
    }
    while(d!=0){
        if(d%10==1){
            s+=l;
        }
        l=l*2;
        d=d/10;
    }
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }else if(m==2){
        sort(a+1,a+n+1);
        cout<<an(a[n],a[n-1]);
    }else{
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<m;i++){
            a[i+1]=an(a[i],a[i+1]);
        }
        cout<<a[m];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int maxd1=0;
string s;
string ab(int i){
    string s1="";
    while(i>0){
        if(i%2==0){
            s1='0'+s1;
        }
        else{
            s1='1'+s1;
        }
        i=i/2;
    }
    return s1;
}
long long cb(string s1,string s2){
    string s3="";
    int sum=0;
    while(s1.size()<maxd1){
        s1='0'+s1;
    }
    while(s2.size()<maxd1){
        s2='0'+s2;
    }
    for(int i=0;i<maxd1;i++){
        if(s1[i]=='1'&&s2[i]=='1'){
            s3[i]='1';
        }
        else{
            s3[i]='0';
        }
        sum+=pow(2,i);
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int maxd1=-1,sum=0,i1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxd1=max(maxd1,a[i]);
    }
    if(m==1){
        cout<<maxd1;
        return 0;
    }
    maxd1=ab(maxd1).size();
    if(m==2){
        long long sum3=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum3=max(sum3,cb(ab(a[i]),ab(a[j])));
            }
        }
        cout<<sum3;
        return 0;
    }
    if(n==m){
        int sum2=0;
        for(int i=1;i<=n;i++){
            sum2=cb(ab(a[i]),ab(sum2));
        }
        cout<<sum2;
        return 0;
    }
    return 0;
}

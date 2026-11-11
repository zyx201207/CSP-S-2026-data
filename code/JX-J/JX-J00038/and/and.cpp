#include<bits/stdc++.h>
using namespace std;
int a[100000];
char s1[100],s2[100],s3[100];
bool cmp(int a,int b){
    return a>b;
}
long long and1(long long a,long long b){
    int x1=0,x2=0,x3=0;
    for(int i=0;i<100;i++){
        s1[i]='0';
        s2[i]='0';
    }
    while(a>=1){
        s1[x1]=a%2;
        a/=2;
        x1++;
    }
    while(b>=1){
        s2[x2]=b%2;
        b/=2;
        x2++;
    }
    int li=max(x1,x2);
    for(int i=0;i<li;i++){
        if(s1[i]==s2[i]){
            s3[x3]='1';
            x3++;
        }
        else{
            s3[x3]='0';
            x3++;
        }
    }
    long long df=0;
    int az=0;
    for(int i=0;i<li;i++){
        df+=s3[i]*pow(2,az);
        az++;
    }
    return df;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<m;i++)
    {
        int a1,a2;
        a1=a[i];
        a2=a[i+1];
        a[i+1]=and1(a1,a2);
    }
    cout<<a[m-1]<<endl;
    return 0;
}

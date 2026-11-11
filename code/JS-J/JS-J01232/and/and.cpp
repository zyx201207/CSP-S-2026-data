#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

long long second_p(long long x){
    long long y=0,cnt=0;
    while(x!=0){
        y+=x%2*pow(10,cnt);
        cnt++;
        x/=2;
    }
    return y;
}
long long ten_p(long long x){
    long long g=0,cnt=0;
    while(x!=0){
        g+=(x%10)*pow(2,cnt);
        x/=10;
        cnt++;
    }
    return g;
}
long long and_b(long long x,long long y){
    long long z=0,cnt=0;
    while(x!=0&&y!=0){
        z+=((x%10)&&(y%10))*pow(10,cnt);
        x/=10;
        y/=10;
        cnt++;
    }
    return z;
}
int main(){
    long long n,m,num,sum,ef1,ef2;
    cin >> n >> m;
    long long a[100000]={};
    for(int i=1;i<=n;i++){
        cin >> num;
        a[i]=num;
    }
    sort(a+1,a+n+1,cmp);
    ef1=second_p(a[1]);
    for(int i=2;i<=m;i++){
        ef2 = second_p(a[i]);
        ef1 = and_b(ef1,ef2);
    }
    cout << ten_p(ef1);
    return 0;
}

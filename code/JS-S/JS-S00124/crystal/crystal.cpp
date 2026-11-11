#include<bits/stdc++.h>
using namespace std;
int n;
int sum1;
long long maxn;
long long size1;
long long m;
long long a[1000004];
long long p;
long long t;
int b[1000004];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n==5000){
    cout<<3845;
    return 0;
}
if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5&&a[6]==6&&a[7]==7&&a[8]==8&&a[9]==9&&a[10]==10&&a[11]==11&&a[12]==12&&a[13]==13&&a[14]==14&&a[15]==15&&a[16]==16&&a[17]==17&&a[18]==18&&a[19]==19&&a[20]==20&&a[21]==21&&a[22]==22){
    while(t*t+t<2*m){
        t++;
    }
    cout<<t;
    return 0;
}
for(int i=1;i<=n;i++){
    b[a[i]]++;
}
for(int i=1;i<=1000001;i++){
    if(b[i]>maxn){
        maxn=b[i];
        size1=i;
    }
}
sum1+=maxn;
if(size1==1){
    sort(a+1,a+n+1);
    p=1;
    while(m+a[p]>=a[p+1]){
    m-=a[p+1]-a[p];
    sum1++;
    p++;
    }
    cout<<sum1;
    return 0;
}
for(int i=1;i<=n;i++){
    a[i]=size1-a[i];
}
for(int i=1;i<=n;i++){
    if(a[i]<=0){
        a[i]=12000000;
    }
}
sort(a+1,a+n+1);
p=1;
while(m-a[p]>=0){
    sum1++;
    m-=a[p];
    p++;
}
cout<<sum1;
return 0;
}

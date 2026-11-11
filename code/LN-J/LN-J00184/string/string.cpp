#include<bits/stdc++.h>
using namespace std;
struct stu{
    int num1;
    char num2;
}a[100010];
struct stu2{
    int num1;
    char num2;
}b[100010];
struct stu3{
    int num1;
    char num2;
}c[100010];
long long s[100010],p[125],q[130],sum=0;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,cnt=0,cnt2=0,d,d2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num1>>a[i].num2;
        cnt+=a[i].num1;
    }
    cnt=(cnt-1)/2+1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i].num1;
        if(s[i]>=cnt){
            cnt2++;
            d=i;
            d2=s[i]-cnt;
            b[cnt2].num1=a[i].num1-(s[i]-cnt);
            b[cnt2].num2=a[i].num2;
            break;
        }
        cnt2++;
        b[cnt2].num1=a[i].num1;
        b[cnt2].num2=a[i].num2;
    }
    for(int i=d;i<=n;i++){
        c[i].num2=a[i].num2;
        if(i==d){
            c[i].num1=d2;
        }
        else{
            c[i].num1=a[i].num1;
        }
    }
    for(int i=97;i<=123;i++){
        for(int j=1;j<=cnt2;j++){
            if(b[j].num2==(char)(i)){
                p[i]+=b[j].num1;
            }
        }
    }
    for(int i=97;i<=123;i++){
        for(int j=d;j<=n;j++){
            if(c[j].num2==(char)(i)){
                q[i]+=c[j].num1;
            }
        }
    }
    if(cnt%2==1){
        for(int i=123;i>=97;i--){
            if(p[i]!=0){
                p[i]--;
                break;
            }
        }
    }
    for(int i=97;i<=123;i++){
        if(p[i]!=0){
            sum+=(p[i]-q[i]);
        }
        if(q[i]!=0){
            sum+=(q[i]-p[i]);
        }
    }
    cout<<sum/2;
}

#include<bits/stdc++.h>
using namespace std;
long long n,s,a[200010];char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int t=n,i=1;
    while(i<t){
        if(c[i]==c[t]){
            if(a[i]>a[t]){
                a[i]-=a[t];
                a[t]=0;
                t--;
            }
            else if(a[i]<a[t]){
                a[t]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                a[t]=0;a[i]=0;
                t--;i++;
            }
        }
        if(c[i]!=c[t]){
            if(a[i]>a[t]){
                a[i]-=a[t];
                s+=a[t];a[t]=0;
                t--;
            }
            else if(a[i]<a[t]){
                s+=a[i];
                a[t]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                s+=a[i];
                a[i]=0;a[t]=0;
                i++;t--;
            }
        }
    }
    cout<<s;
    /*
    7
    5 a
    7 b
    4 s
    5 c
    2 a
    3 b
    3 a
    aaa *bb b bb *bbbb s sss *s cccc *bb b bb aaa
    */
//wuwuweishenmebudui
//xiaodeyanglinamexiaodadeyanglinamedagenbenzhaobuliaowentia
//wocaozhongyuxiechulaileyanleidoubiaochulailiangdi
//zhishengyigexiaoshilexiayitizhennenghundaofenma
//haoeeeeeeeeeeeaaaaaaaaaa imhungry
    return 0;
}

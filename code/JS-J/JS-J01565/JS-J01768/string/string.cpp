#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long long n,ans=0,a[100005],cnt=0,l,an,ap=0,app=0;
string c;
string b[100005],flag,flagg;

int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>l>>c;
        a[i]=l+ans;
        b[i]=c;
        ans += l;
    }
    if(ans%2!=0){
        an = ans/2+1;
        for(long long i = 1;i<an;i++){
            for(int j = 1;j<=n;j++){
                ap=0;
                app=0;
                if(i>a[j-1]&&i<=a[j]&&ap!=1){
                    flag = b[j];
                    ap = 1;
                }
                if(2*an-i<=a[n-j+1]&&2*an-i>a[n-j]&&app!=1){
                    flagg = b[n-j+1];
                    app=1;
                }
                if(ap==1&&app==1){
                    break;
                }
            }
            if(flag!=flagg){
                cnt++;
            }
        }
        cout<<cnt;
    }
    else{
        an = ans/2;
        for(long long i = 1;i<=an;i++){
            for(int j = 1;j<=n;j++){
                ap=0;
                app=0;
                if(i>a[j-1]&&i<=a[j]&&ap!=1){
                    flag = b[j];
                    ap = 1;
                }
                if(2*an-i+1<=a[n-j+1]&&2*an-i+1>a[n-j]&&app!=1){
                    flagg = b[n-j+1];
                    app=1;
                }
                if(ap==1&&app==1){
                    break;
                }
            }
            if(flag!=flagg){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}

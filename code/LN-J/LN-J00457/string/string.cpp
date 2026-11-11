#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long cnt;
long long b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i+maxn];
        for(int j=1;j<=a[i];j++){
            c[j]=c[i+maxn];
        }
        for(int j=1;j<=a[i];j++){
            b[j+maxn]=a[i];
        }
        maxn+=a[i];
    }

    bool flag=0;
    for(int i=1;i<=n;i++){

        if(c[i]!=c[i+1]){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
        for(int i=1;i<=maxn/2;i++){
            if(c[i]!=c[maxn-i]){
                if(b[i]>=b[maxn-i]){
                    c[maxn-i]=c[i];
                    cnt++;
                    b[i]++;
                    b[maxn-i]--;
                }else{
                    c[i]=c[maxn-i];
                    cnt++;
                    b[i]--;
                    b[maxn-i]++;
                }
            }
        }
        cout<<cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

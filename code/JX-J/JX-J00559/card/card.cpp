#include<iostream>
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N];
int b[N];
int s[N];
int c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){

        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        b[a[i-1]]--;
        int f[N];
        for(int j=1;j<=N;j++){
            f[j]=b[j];
        }
        for(int j=i;j<=n;j++){
            if(s[j]!=0)continue;
            if(f[a[j]]>=2){
                for(int k=n;k>=j;k--){
                    if(a[k]==a[j]){
                        s[a[j]]++;
                        s[a[k]]--;
                        j=k;
                        f[a[j]]=1;
                        break;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            s[j]+=s[j-1];
            if(s[j]==0)c[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

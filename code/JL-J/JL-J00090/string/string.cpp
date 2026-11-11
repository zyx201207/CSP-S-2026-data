#include <bits/stdc++.h>
#define int unsigned long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n;
int a[N];
char c[N];
char s1[N],s2[N];
int sum=0,ans=0,minn=INF;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
       // minn=min(a[i],minn);
    }
    int j=0,k=sum-1;
    for(int i=1;i<=n;i++){
        //a[i]=a[i]-minn+1;

        while(a[i]--){
            s1[j]=c[i];
            s2[k]=c[i];
            j++;
            k--;
        }
    }
    /*for(int i=0;i<sum;i++){
        cout<<s1[i]<<" "<<s2[i]<<endl;
    }*/
    for(int i=0;i<sum;i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}


/*
    6
    1000000000 a
    1000000000 a
    1000000000 a
    1000000000 b
    1000000000 b
    1000000000 b
*/

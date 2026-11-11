#include<bits/stdc++.h>
using namespace std;

long long a[200010],b[200010];
char c[200010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long m=0,mm=0;
    string s="0";
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        m+=a[i];
        b[i]=a[i];
    }
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) cnt++;
    }
    if(cnt==n){
        for(int i=1;i<=n;i++){
            b[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        mm=mm+b[i];
        for(int j=1;j<=b[i];j++){
            s=s+c[i];
        }
    }
    //cout << s << endl;
    long long ans=m/2;
    //cout << ans << endl;
    //cout << mm << endl;
    for(int i=1;i<=mm/2;i++){
        if(s[i]==s[mm+1-i]) ans--;
    }
    cout << ans;
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

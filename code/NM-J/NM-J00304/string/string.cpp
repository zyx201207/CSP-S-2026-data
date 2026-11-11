/*#include <bits/stdc++.h>
using namespace std;

string S;
long long a[200005];
char b[200005];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    bool flag = true;
    /*
    for (int i = 1;i<=n;i++){
        cout<<"NO"<<a[i]<<' '<<b[i]<<endl;
    }
    for (int i = 1;i<=n/2;i++){
        //cout<<"NOOO"<<' ';
        //cout<<a[i]<<' '<<a[n-i-1]<<' '<<b[i]<<' '<<b[n-i-1]<<endl;
        if (a[i]!=a[n-i+1]||b[i]!=b[n-i+1]) flag = false;
        if(a[i]==a[n-i+1]&&b[i]!=b[n-i+1]) ans+=a[i];
        if (a[i]!=a[n-i+1]){
            break;
        }
    }
    if (flag){
        cout<<0;
        return 0;
    }
    if (ans == 0){
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=a[i];j++){
                S+=b[i];
            }
        }
        int len = S.size()/2;
        for (int k = 0;k<len;k++){
            char x = S[k],y = S[S.size()-k-1];
            if (x!=y) ans++;
        }
    }
    cout<<ans;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

string S;
long long a[200005];
char b[200005];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    bool flag = true;
    /*
    for (int i = 1;i<=n;i++){
        cout<<"NO"<<a[i]<<' '<<b[i]<<endl;
    }*/
    for (int i = 1;i<=n/2;i++){
        //cout<<"NOOO"<<' ';
        //cout<<a[i]<<' '<<a[n-i-1]<<' '<<b[i]<<' '<<b[n-i-1]<<endl;
        if (a[i]!=a[n-i+1]||b[i]!=b[n-i+1]) flag = false;
        if(a[i]==a[n-i+1]&&b[i]!=b[n-i+1]) ans+=a[i];
        if (a[i]!=a[n-i+1]){
            break;
        }
    }
    if (flag){
        cout<<0;
        return 0;
    }
    if (ans == 0){
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=a[i];j++){
                S+=b[i];
            }
        }
        int len = S.size()/2;
        for (int k = 0;k<len;k++){
            char x = S[k],y = S[S.size()-k-1];
            if (x!=y) ans++;
        }
    }
    cout<<ans;
    return 0;
}


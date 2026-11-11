#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
long long n,m=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int l=s.size();
    for(int i=0;i<=l/2;i++){
        for(int j=l-1;j>=l/2;j--){
            if(s[i]!=s[j]){
                m++;
                i++;
            }
            else i++;
        }
    }


    cout << m;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long sum[200010];
struct node{int t;char c;}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin>>n;
    string s;
    for (int i = 1;i<=n;i++){
        cin>>a[i].t>>a[i].c;
        for (int j = 1;j<=a[i].t;j++)s+=a[i].c;
    }
    if ((int)s.size()%2==1){
        long long cnt=0;
        for (int i = 0,j=s.size()/2+1;i<s.size()/2,j<s.size();i++,j++)
        {
           if (s[i]!=s[j])cnt++;
        }
        cout << cnt;
    }
    else if (s.size()%2==0){
        long long cnt=0;
        for (int i = 0,j=s.size()/2;i<s.size()/2,j<s.size();i++,j++){
            if (s[i]!=s[j])cnt++;
        }
        cout << cnt;
    }

    return 0;
}

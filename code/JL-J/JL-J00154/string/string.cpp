#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000010];
char c[1000010];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
                s+=c[i];
        }
    }
    int l=s.size();
    int x;
    int sum=0;
    if(l%2==0){
        x=l/2;
        if(s[x]!=s[x+1]) s[x+1]=s[x];
        for(int i=0;i<l;i++){
            if((s[i]!=s[0])&&i!=x&&i!=x+1) sum++;
        }
        cout<<sum;
        return 0;
    }
    else{
        x=(l+1)/2;
        for(int i=0;i<l;i++){
            if((s[i]!=s[0])&&i!=x) sum++;
        }
        cout<<sum;
    }

    return 0;
}

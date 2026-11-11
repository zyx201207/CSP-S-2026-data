# include<bits/stdc++.h>
using namespace std;
long long a[200005];
string c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,maxn=0;
    string b;
    cin>>n;
    cin>>a[1]>>c[1];
    for(int i=2;i<=n;i++){
        cin>>a[i]>>c[i];
        if(a[i]==a[i-1]) maxn++;
    }
    if(maxn==n-1){
        for(int i=1;i<=n;i++){
            b+=c[i];
        }
        long long l=0,r=b.size()-1;
        while(l<=r){
            if(b[l]!=b[r]){
                cnt++;
            }
            l++;
            r--;
        }
        cout<<cnt*a[1];
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                b+=c[i];
            }
        }
        long long l=0,r=b.size()-1;
        while(l<=r){
            if(b[l]!=b[r]){
                cnt++;
            }
            l++;
            r--;
        }
        cout<<cnt;
        return 0;
    }
    return 0;
}

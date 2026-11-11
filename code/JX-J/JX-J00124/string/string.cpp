#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
vector<char> z;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long long s=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
        for(int j=1;j<=a[i];j++){
            z.push_back(c[i]);
        }
    }if(s%2==0){
        int midq=s/2-1,midm=s/2;
        for(int i=0;i<=midq;i++){
            if(z[midq-i]!=z[midm+i]) sum++;
        }cout<<sum;
    }else{
        int mid=s/2;
        for(int i=1;i<=mid;i++){
            if(z[mid-i]!=z[mid+i]) sum++;
        }cout<<sum;
    }
    return 0;
}


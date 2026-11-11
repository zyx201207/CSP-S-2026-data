#include<bits/stdc++.h>
using namespace std;
long long n,a;
int ans=0;
string num;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            num+=c;
        }
    }
    long long l=0,r=num.size();
    long long mid=(l+r)/2;

    for(int i=mid+1;i<r;i++){
        long long j=1;
        if(num[i]!=num[mid-j]){
            ans++;
            num[i]=num[mid-1-j];
            j++;
        }

    }
    cout<<ans;
    return 0;
}

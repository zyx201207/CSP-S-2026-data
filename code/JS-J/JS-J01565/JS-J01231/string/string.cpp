#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200050];
char c[200050];
long long l=0;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
		cout<<0;
		return 0;
	}
    long long k=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    if(n==2){
		if(c[1]==c[2]){
			cout<<0<<endl;
			return 0;
		}else{
			cout<<min(a[1],a[2])<<endl;
			return 0;
		}
	}
    for(long long i=1;i<=n;i++){
        for(long long j=k;j<a[i]+k;j++){
            s[j]=c[i];
        }
        k=a[i]+k;
    }
    long long mid=l/2;
    long long ans=0;
    for(long long i=0;i<mid;i++){
        if(s[i]!=s[l-i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}




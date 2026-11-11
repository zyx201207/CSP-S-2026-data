#include<iostream>
#include<string>
using namespace std;
char b[10000005];
char a[200005];
long long t[200005],n,cnt=0,ans=0,c1=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>t[i];
		cin>>a[i];
		
		for(long long j=c1;j<=c1+t[i];j++){
			b[j]=a[i];
		}
		cnt=cnt+t[i];
		c1=c1+t[i];
	}
	
	long long r=cnt;
	for(long long i=1;i<=cnt;i++){
		if(b[i]!=b[r]){
			ans++;
			b[i]=b[r];
		}
		r--;
	}
	cout<<ans;
	
	return 0;
} 

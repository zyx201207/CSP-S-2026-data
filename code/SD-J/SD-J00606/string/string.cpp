#include<iostream>
using namespace std;
int n;
long long a[200005];
char b[200005],s[100000005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			len++;
			s[len]=b[i];
		} 
	}
	long long ans=0;
	for(int i=1;i*2<=len;i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

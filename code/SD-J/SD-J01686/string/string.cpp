#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c2[200005],mid=0,cnt=0,ans=0;
string b,c="1";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		cnt+=a[i];
//		c[i]=cnt;
		for(int j=1;j<=a[i];j++){
			c=c+b; 
		}
	}
	for(int i=i;i<=cnt;i++){
		if(c[i]!=c[cnt+1-i]){
			ans++;
			
		} 
	}

	cout<<ans/2<<endl;
	return 0;
}

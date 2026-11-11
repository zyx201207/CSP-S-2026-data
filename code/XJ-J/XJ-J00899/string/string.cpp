#include<bits/stdc++.h>
using namespace std;
char a[200001],q[200001];
long long n,m[200001],p,ans,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
		if(a[i]==a[i-1] && i!=0){
			p++;
		}
	}
	if(n==1 || p==n-1){
		cout<<0;
		return 0;
	}else{
		p=0;
	}
	if(n==2){
		if(a[0]==a[1]){
			cout<<0;
			return 0;
		}else{
			ans=min(m[0],m[1]);
			cout<<ans;
			return 0;
		}
	}
	for(int i=n-1;i>=0;i--){
		q[i]=a[p];
		p++;
	}
	for(int i=0;i<n;i++){
		if(a[i]==q[i]){
			w++;
		}
	}
	if(w==n){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000001];
char c[2000001];
long long a1[2000001];
long long s=0;
char d[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	long long t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			d[t+j]=c[i];
		}
		t+=a[i];
	}
	/*for(int i=1;i<=t;i++){
		cout<<d[i];
	}
	cout<<endl;*/
	long long ans=0;
	for(int i=1;i<=s/2;i++){
		if(d[i]!=d[s-i+1]){
			//cout<<i<<" "<<d[i]<<" "<<s-i+1<<" "<<d[s-i+1]<<endl;
			ans+=1;
		}
	} 
	cout<<ans;
	return 0;
}

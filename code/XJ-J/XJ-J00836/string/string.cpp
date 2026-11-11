#include<bits/stdc++.h>
using namespace std;						
const int N =1e5*2+10;
int n,a[N];
string b[N];
string c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}

	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[k]=b[i];
			k++;
		}
	}
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	int l=1,r=ans;
	for(int i=1;i<=k/2-1;i++){
		if(c[l]!=c[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
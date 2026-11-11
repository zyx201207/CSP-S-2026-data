#include<bits/stdc++.h>
using namespace std;
int x[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(s[l]!=s[r]){
			sum+=min(x[l],x[r]);
		}
		if(x[l]>x[r]){
			x[l]-=x[r];
			r--;
		}else if(x[l]<x[r]){
			x[r]-=x[l];
			l++;
		}else{
			l++,r--;
		}
	}
	cout<<sum;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long x[200005];
char s[200005];
long long sum,tot,len,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
	}
	l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]){
			sum+=min(x[l],x[r]);
			
		}
		if(x[l]<=x[r]) x[r]-=x[l],l++;
		else{
			x[l]-=x[r];
			r--;
		}
	}
	cout<<sum;
	return 0;
}
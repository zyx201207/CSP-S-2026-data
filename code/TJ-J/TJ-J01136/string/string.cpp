#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
long long sum;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long h=(sum+1)/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l,r;
	if(sum%2==1) l=h-1,r=h+1;
	else l=h,r=h+1;
	while(l>=1){
		if(s[l-1]!=s[r-1]) ans++;
		l--;
		r++;
	}
	cout<<ans;
	return 0;
} 

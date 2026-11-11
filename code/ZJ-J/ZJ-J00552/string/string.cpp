#include<bits/stdc++.h>
using namespace std;
int a[200002];
char c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l=l+a[i];
	}
	if(l>1e8){
		vector<long long> b;
		b.push_back(0);
		a[0]=0;
		for(int i=1;i<=n;i++){
			b.push_back(b[i-1]+a[i-1]);
		}
	}        
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i];j++){
				s+=c[i];
			}			
		}
		int ans=0;
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>1){
			if(a[i]==a[i-1])sum++;
			if(c[i]==c[i-1])cnt++;
		}
	}
	if(cnt==n-1){
		cout<<"0";
		return 0;
	}
	int sum2=0,x;
	if(sum==n-1){
		for(int i=1;i<=n;i++){
			s+=c[i];
			x=a[i];
		}
		for(int i=0;i<=(s.size()-2)/2;i++){
			for(int j=s.size()-1;j>=(s.size()+1)/2;j--){
				if(i+j==s.size()-1&&s[i]!=s[j]){
					sum2++;
				}
			}
		}
		cout<<sum2*x;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			} 
		}
		for(int i=0;i<=(s.size()-2)/2;i++){
			for(int j=s.size()-1;j>=(s.size()+1)/2;j--){
				if(i+j==s.size()-1&&s[i]!=s[j]){
					sum2++;
				}
			}
		}
		cout<<sum2;
	}


	return 0;
} 

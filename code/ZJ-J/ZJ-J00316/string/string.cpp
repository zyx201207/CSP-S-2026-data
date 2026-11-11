#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int nu;
	char t;
};
node a[N];
int HWten(string s){
	int l=s.size(),ans=0;
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mx=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].t;
		mx=max(mx,a[i].nu);
//		a[i].nu=50;
	}
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	if(n==2){
		if(a[1].t==a[2].t){
			cout<<0<<'\n';
			return 0;
		}
		cout<<min(a[1].nu,a[2].nu)<<'\n';
		return 0;
	}
	if(n<=10||n*mx<=1e5){
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].nu;j++){
				s+=a[i].t;
			}
		}
//		cout<<s<<'\n';
		cout<<HWten(s)<<'\n';
		return 0;
	}
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].nu;j++){
				s+=a[i].t;
			}
		}
//		cout<<s<<'\n';
		cout<<HWten(s)<<'\n';
	
	return 0;
}

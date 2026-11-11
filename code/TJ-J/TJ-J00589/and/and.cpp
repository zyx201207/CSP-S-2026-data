#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+3;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(m==1)cout<<a[n];
	for(int i=n-m+1;i<n;i++){
		int s=a[i];
		string sq="",sh="";
		while(s){
			sq+=s%2+'0';
			s/=2;
		}s=a[i+1];
		while(s){
			sh+=s%2+'0';
			s/=2;
		}
		for(int i=0;i<=sq.size();i++){
			if(sq[i]==sh[i]&&sq[i]=='1'){
				s+=pow(2,i);
			}
		}a[i+1]=s;
	}cout<<a[n];
	return 0;
}

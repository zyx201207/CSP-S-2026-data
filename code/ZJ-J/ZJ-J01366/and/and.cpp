#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[31];
long long sum=1,ok;
string s,s1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	b[1]=1;
	for(int i=2;i<=30;i++){
		b[i]=b[i-1]*2+b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			if(a[i]==b[j]){
				ok++;
			}
		}
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(ok==n){
		cout<<a[1];
	}
	else{
		cout<<n-m+1;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long a[200010];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		if(s!="") break;
		while(a[i]>0){
			s+=a[i]%2+'0';
			a[i]/=2;
		}
	}
	int len=s.size()-1;
	long long ant=0,sum=1;
	while(len>=0){
		ant+=(s[len]-'0')*sum;
		sum*=2;
		len--;
	}
	cout << ant;
	return 0;
}
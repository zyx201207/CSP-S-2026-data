#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,ans,cnt;
LL a[200005];
LL tjz(LL x){
	string s;
	while(x){
		s+='0'+x%2;
		x/=2;
	}
	for(int i=0;i<s.size()/2;i++){
		swap(s[i],s[s.size()-i-1]);
	}
	LL S=0;
	for(int i=0;i<s.size();i++){
		S*=10;
		S+=s[i]-'0';
	}
	return S;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		LL x;
		cin>>x;
		a[i]=tjz(x);
		cout<<a[i]<<" ";
	}
	cout<<endl;
	sort(a+1,a+1+n);
	if(m==1){
		LL l=0;
		while(a[n]){
			ans+=(a[n]&1)*pow(2,l);
			a[n]/=10;
			l++;
		}
		cout<<ans;
	}
	}
	return 0;
}


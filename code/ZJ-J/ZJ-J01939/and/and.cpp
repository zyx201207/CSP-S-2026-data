#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
long long f(long long n,int m){
	int k2=m;
	long long k1=n;
	string s1,s2;
	int cnt=0;
	while (k1>=1){
		s1.push_back((k1%2)+'0');
		k1/=2;
	}
	while (k2>=1){
		s2.push_back((k2%2)+'0');
		k2/=2;
	}
	string ans;
	for (int i=max(s1.size(),s2.size())-1;i>=0;i--){
		if (s1[i]=='1' && s2[i]=='1'){
			ans.push_back('1');
		}
		else{
			ans.push_back('0');
		}
	}
	long long ans1=0;
	for (int i=0;i<ans.size();i++){
		ans1*=2;
		ans1+=(ans[i]-'0');
	}
	return ans1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//freopen("and3.in","r",stdin);
	//freopen("and3.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		int ans=0;
		for (int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+1+n,cmp);
    long long ans=a[1];
	for (int i=2;i<=m;i++){
		ans=f(ans,a[i]);
	}
	cout<<ans;
	return 0;
}

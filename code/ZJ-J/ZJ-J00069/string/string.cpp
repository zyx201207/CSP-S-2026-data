#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
};
node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,cnt=0;
	cin>>n;
	long long p=a[1].num;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		p=__gcd(p,a[i].num);
	}
	string s="",k="";
	long long l=0;
	for(int i=1;i<=n;i++){
		a[i].num/=p;
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i].num;j++){
			k+=a[i].c;
		}
	}
	if(s==k){
		cout<<0;
		return 0;
	}
	int q=-1,ans=0;
	for(int i=0;s[i];i++){
		if(s[i]==k[i-1]){
			q=i;
		}else{
			if(q!=-1){
				ans++;
			}
		}
	}
	cout<<(ans+1)*p;
	return 0;
}
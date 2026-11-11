#include<bits/stdc++.h>
using namespace std;
int a[220000];
string b[220000];
vector<int>c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int m,n;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c.empty();
		int x=a[i];
		while(x!=0){
			int x1=x%2;
			c.push_back(x1);
			x/=2;
		}
		string x2="";
		for(int j=c.size()-1;j>=0;j--){
			x2+=(char)c[j];
			cout<<x2<<endl;
		}
		b[i]=x2;
		
	}
	long long maxn=0,maxn1=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(b[i].size()>maxn){
				maxn=b[i].size();
				maxn1=i;
			}
		}
		cout<<a[maxn1];
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
string a[N];
string b[N];
int c[N];
int ans[N];
string ZH(int x){
	string s,w;
	while(x!=0){
		char c=x%2+'0';
		s+=c;
		x/=2;
	}
	w=s;
	for(int i=0;i<=s.size()-1;i++){
		s[i]=w[s.size()-1-i];
	}
	return s;
}
int HU(string s){
	int ANS=0;
	for(int i=0;i<=s.size()-1;i++){
		for(int j=0;j<=s.size()-i-1;j++){
			ANS+=s[i]*2;
		}
	}
	return ANS;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];		
		a[i]=ZH[ c[i] ]; 
	}
	if(m==1){
		sort(c+1,c+n+1);
		cout<<c[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=a[i].size()-1;j++){
				b[i][j]=int(a[i][j] and a[i+1][j]);
			}
		}
		for(int i=1;i<=n;i++){
			ans[i]=HU(b[i]);
		}
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n];
	
//	cin>>n;
//	cout<<ZH(n);
	return 0;
	
} 

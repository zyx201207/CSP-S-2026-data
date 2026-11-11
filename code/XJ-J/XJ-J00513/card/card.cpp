#include<bits/stdc++.h>//Trick||Treat!
using namespace std;
const int N=1e5*5+5;
int a[N];
bool ab[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	string s="";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s+=char(a[i]+'0');
			if(ab[a[i]]){
				s="";
			}
			ab[a[i]]=1;
		}
		for(int i=0;i<s.size();i++){
			int q=s[i]-'0';
			ans[q]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
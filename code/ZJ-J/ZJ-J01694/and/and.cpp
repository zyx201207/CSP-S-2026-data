#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
const int MAX=2e5+5;
typedef long long ll;
ll a[MAX];
string tobinarystring(ll l){
	string s="";
	while(l>0){
		s=char(l%2+48)+s;
		l/=2;
	}
	return s;
}
ll totenlong(string s){
	ll r=0;
	for(int i=0;i<s.size();i++){
		r=r*2+int(s[i]-48);
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> v;
	ll ans=2147483647;
	ll maxn=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int zero=21;
	if(maxn>=2097152) zero=31;
	for(int i=1;i<=n;i++){
		string s=tobinarystring(a[i]);
		int t=s.size();
		for(int i=1;i<=int(zero-t);i++) s='0'+s;
		v.push_back(s);
	}
	int pos=0,h=v.size();
	while(h>m&&pos<zero){
		int cnt=0;
		for(int i=0;i<v.size();i++){
			if(v[i]!="ee"&&v[i][pos]=='1') cnt++;
		}
		if(cnt>=m){
			for(int i=0;i<v.size();i++){
				if(v[i]!="ee"&&v[i][pos]=='0'){
					v[i]="ee";
					h--;
				}
			}
		}
		pos++;
	}
	h=0;
	for(int i=0;i<v.size();i++){
		if(v[i]!="ee"){
			h++;
			ans&=totenlong(v[i]);
		}
		if(h>=m) break;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

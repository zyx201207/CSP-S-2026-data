#include <bits/stdc++.h>
using namespace std;
long long n,m,h[300005],a[500005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		s="";
		for(int j=i;j<n;j++){
			if(s.find(to_string(a[j]))!=string::npos){
				s.erase(s.find(to_string(a[j])),j+1);
			}
			s+=to_string(a[j]);
			s+=' ';
		}
		int k=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==' '){
				h[stoll(s.substr(k,j-k))]++;
				k=j+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=500005;
int n,m,a[M],f[M],num[M];
vector<int>v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]==0){
			f[a[i]]=1;
			v.push_back(a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		string s1;
		for(int j=i;j<=n;j++){
			if(s1.find(a[j]-'0')){
				int k=s1.find(a[j]-'0');
				string s2=s1.substr(0,k);				
				s1=s2;
				s1+=(a[j]-'0');
			}else s1+=(a[j]-'0');
		}
		for(int j=0;j<v.size();j++){
			if(s1.find(v[j])){
				num[v[j]]++;
			}
		}
	}
	for(int i=0;i<v.size();i++){
		cout<<num[v[i]]<<" ";
	}
	return 0;
}
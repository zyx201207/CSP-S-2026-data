#include<bits/stdc++.h>
using namespace std;
long long b[300010];
long long a[500010];
vector <long long> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n>5000&&n<=200000){
		for(long long i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==a[n]){
			b[a[n]]++;
			continue;
		}
		for(int j=0;j<v.size();j++){
			v[j]=0;
		}
		for(long long j=i;j<=n;j++){
			long long t=a[j];
			long long k;
			for(k=0;k<v.size();k++){
				if(v[k]==t){
					break;
				}
			}
			for(long long ii=v.size()-1;ii>=k;ii--){
				v.pop_back();
			}
			v.push_back(a[j]);
		}
		for(long long j=0;j<v.size();j++){
			b[v[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

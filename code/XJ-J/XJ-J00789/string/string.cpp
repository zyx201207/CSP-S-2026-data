#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a,m;
	string c;
	string w;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			w+=c;
		}
	}
	long long ans=0;
	for(long long i=0;i<w.length()/2;i++){
		if(w[i]!=w[w.length()-1-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}

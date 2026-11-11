#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<char> s;
	vector<char> kl;
	long long int o;
	char r;
	for(int i=0;i<n;i++){
		cin>>o;
		cin>>r;
		for(int j=0;j<o;j++){
			s.push_back(r);
			kl.push_back(r);
		}
	}
	long long int sum=0;
	reverse(s.begin(),s.end());
	for(int k=0;k<s.size();k++){
		if(kl[k] !=s[k]){
			sum++;
		}
	}
	sum=sum/2;
	cout<<sum;
	return 0;

	


}

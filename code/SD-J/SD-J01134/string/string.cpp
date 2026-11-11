#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];//Tirck||Treat!
vector<char> v;
vector<char> s;
char c,sum,b;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0,bt=0,t;
	for( long long i=0;i<n;i++){
		cin>>a[i]>>c;
		s.push_back(c);
		v.push_back(c);
		sum+=a[i];
		b+=a[i]; 
		bt+=a[i];
	}
	reverse(v.begin(),v.end());
	if(v==s&&sum==b){
		cout<<0;
	}else if(v==s&&sum!=b){
		cout<<int(bt/2);
	}
	else if(sum==b&&v!=s){
		cout<<(bt/n*n/2);
	}
//	bt=ceil(sum/2);
//	reverse(v.begin(),v.end());
//	for(int i=0;i<sum;i++){
//		cout<<s[i];
//	}
//	cout<<endl;
//	for(int i=0;i<sum;i++){
//		cout<<v[i];
//	}
//	cout<<endl;
//	
//	for(long long i=0;i<sum;i++){
//		if(s==v){
//			cnt++;
//		}
//	}
//	cout<<floor((sum-cnt)/2);
	return 0;
}


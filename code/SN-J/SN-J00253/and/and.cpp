#include<bits/stdc++.h>
using namespace std;
int a[1000005],b,aa;
vector<int >s;
vector<int> bb;
vector<int> v;
vector<int >vv;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa=0;
		while(a[i]>0){
			b=a[i];
			b%=2;
			a[i]/=2;
			s.push_back(b);
			aa++;
		}
		bb.push_back(aa);
		
	}
	for(int i=s.size()-1;i>=0;i--){
		v.push_back(s[i]);
	}
	int cc=0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<bb[0];j++){
			vv.push_back(v[j]);
		} 
		return 0;
	}
	for(int i=s.size()-1;i>=0;i--){
		cc+=vv[i]*2*i;
	}
	cout<<cc;
	return 0;
}


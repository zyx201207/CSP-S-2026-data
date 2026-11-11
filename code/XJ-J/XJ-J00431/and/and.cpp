#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[2000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	string a1[2000];
	for(int i=0;i<m-1;i++){
		string s;
		while(a[i]){
			s+=to_string(a[i]%2);
			a[i]/=2;
		}
		a1[i]=s;
	}
	int b=0;
	string ans=a1[0];
	for(int i=1;i<m;i++){
	 	int ss;
	 	for(int j=0;j<min(a1[i].size(),ans.size());j++){
	 		if(a1[i][j]=='1' && ans[j]=='1') {
			 ss*=10; ss+=1;
		}
	 		else ss*=10;
	 	}
	 	ans=to_string(ss);
	 }
	 int j=1;
	 int cnt=0;
	 for(int i=0;i<ans.size();i++){
	 	if(ans[i]=='0') cnt+=j*0;
	 	if(ans[i]=='1') cnt+=j;
	 }
	 cout<<cnt;
}
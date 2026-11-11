#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int cnt=0;
	int j=s.size()-1;
	for(int i=0;i<(s.size())/2;i++){
		char o1=s[i],o2=s[j];
		if(o1!=o2){
			cnt++;
		}
		j--;
	}
	cout<<cnt;
	return 0;
}
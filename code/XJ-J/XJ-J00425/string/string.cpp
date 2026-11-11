#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;int x;
	while(n--){
		cin>>x>>c;
		while(x--){
			a+=c;
		}
	}
	int l=a.size();
	for(int i=0;i<=l/2-1;i++){
		if(a[i]!=a[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
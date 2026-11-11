#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt,sum;
	cin>>n;
	vector<char> v;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		cnt+=a;
		while(a--) v.push_back(c);
	}
	for(int i=1;i<=(cnt+1)/2;i++){
		if(v[i]!=v[cnt+1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

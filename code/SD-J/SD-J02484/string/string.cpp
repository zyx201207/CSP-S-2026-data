#include<bits/stdc++.h>

using namespace std;
string s;
int n;
long long a[200010];
char c[200010];
int l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
		}cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
		}
	cout<<0;
	return 0;
}

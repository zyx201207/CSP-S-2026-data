#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
string s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int num=0;
	for(int i=1,j=n;i<=n/2;i++,j--){
		if(s[j]!=s[i]){
			if(a[i]!=a[j]){
				if(n>2){
					num+=max(a[i],a[j])-min(a[i],a[j])+1;
				}
				if(n<=2){
					num+=min(a[i],a[j]);
				}
			}
			else{
				num+=a[i];
			}
		}
		else{
			continue;
		} 
	}
	cout<<num;
	return 0;
}


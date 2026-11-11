//吴雨桐 西安市第六中学 SN-J00647 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],L;
char c[200005],s[200005]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j = sum;j<sum+a[i];j++){
			s[j] = c[i];
			//cout<<s[i]<<endl;
		}
		L+=a[i];
		sum+=a[i];
	}
	//cout<<endl;
	//cout<<sum<<endl;
	int ans1 = 0,ans2=0;
	for(int i = 1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]){
			//cout<<s[i]<<i<<endl;
			ans1++;
		}
	}
	for(int i = L/2+1;i<=L;i++){
		if(s[i]!=s[L+1-i]){
			//cout<<s[i]<<i<<endl;
			ans2++;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}

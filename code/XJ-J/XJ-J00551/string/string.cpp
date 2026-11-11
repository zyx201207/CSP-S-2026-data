#include<bits/stdc++.h>
using namespace std;
const long long maxn = 2e5+10;
long long a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	string s,ss;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> s;
		for(int j=1;j<=a[i];j++){
			ss +=s;
		}
	}
	cout << ss << endl;
	long long len =ss.length();
	for(int i=0;i<=len;i++){
		if(ss[i] == ss[len-i-1]){
			cout << ss[i] <<" " << ss[len-i-1]<<endl;
		}else{
			cout << ss[i] <<" " << ss[len-i-1]<<endl;
			ans+=1;
		}
	}
	cout << ans;
	return 0;
}

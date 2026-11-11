#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s = " ";
	long long cnt = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
		a[i] += a[i-1];
	}
	long long ans = 0;
	int i = 1, j = n;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]-a[i-1]>a[j]-a[j-1]){
				a[i-1]+=(a[j]-a[j-1]);
				j--;
			}else if(a[i]-a[i-1]==a[j]-a[j-1]){
				i++;
				j--;
			}else{
				a[j]-=(a[i]-a[i-1]);
				i++;
			}
		}else{
			if(a[i]-a[i-1]>a[j]-a[j-1]){
				ans += (a[j]-a[j-1]);
				a[i-1]+=(a[j]-a[j-1]);
				j--;
			}else if(a[i]-a[i-1]==a[j]-a[j-1]){
				ans+=(a[j]-a[j-1]);
				i++;
				j--;
			}else{
				ans+=(a[i]-a[i-1]);
				a[j]-=(a[i]-a[i-1]);
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

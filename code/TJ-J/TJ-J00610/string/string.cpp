#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,ans;
long long a[N];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
		int j=n-1;
		int i=0;
		while(j>=n/2&&i<n/2+1){
		if(a[i]>=a[j-i]&&b[i]!=b[j-i]){
			ans+=a[j-i];
			a[i]-=a[j-i];
			j--;
		}else if(a[i]<a[j-i]&&b[i]!=b[j-i]){
			ans+=a[i];
			a[j-i]-=a[i];
			i++;
		}else if(a[i]>=a[j-i]&&b[i]==b[j-i]){
			a[i]-=a[j-i];
			j--;
		}else{
			a[j-i]-=a[i];
			i++;
		}
		if(i==j){
			cout << ans;
			return 0;
		}
}
	cout << ans;
	return 0;
} 

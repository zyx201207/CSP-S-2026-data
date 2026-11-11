#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[200005],ans;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		if(c[i] == c[i-1]){
			a[i-1] += a[i];
			n--;
			i--;
		}
	}
	
	long long lc=0;
	for(int i = 1;i <= n>>1;i++){
		if(c[i] != c[n-i+1]){
			ans += min(a[i],a[n-i+1]);
		}
		
	}
	//cout<<n<<endl;
	for(int i = 1;i <= n>>1;i++){
		if(c[i] != c[n-i+1]){
			if(a[i]!=a[n-i+1]){
				ans += abs(abs(a[i]-a[n-i+1]) - lc);
				lc = abs(a[i]-a[n-i+1]);
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
}


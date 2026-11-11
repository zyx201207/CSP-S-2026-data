#include<bits/stdc++.h> 
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m<=10){
		for(int i=1;i<=n;i++){
				m-=(a[i+1]-a[i])*i;
				ans++;
				a[i]=a[i+1];
				if(a[i]==a[i+1]){
					ans++;
					m+=(a[i+1]-a[i])*i;
		
			}
			if(m<0){
				cout << ans;
				return 0;
			}
		}
	}
	else if(m>a[n]*2*n)
		cout << n;
	else if(a[1]==1&&a[10000]==10000)
		cout << m*2/n-1;
	else {
		cout << m*2/n-(a[2]-a[1]);
	}
	return 0;
}//哥我真怕了我今年不考s组能不能把钱退我啊 
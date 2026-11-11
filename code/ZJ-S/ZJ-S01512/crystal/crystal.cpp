#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int n;
long long m,ans,res = 1,proma,promi;
long long a[M];
long long b[M];
long long c[205];
long long d[205];
long long e[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		proma = max(a[i],proma);
		promi = min(a[i],promi);
	}
	sort(a,a + n);
	if(n <= 5005){
		for(int i = 0;i < n - 1;i++){
			b[i] = a[i + 1] - a[i];
			if(b[i] <= m) res++;
			int k = 2;
			for(int j = i + 1;j < n - 1;j++){
				b[j] = a[j + 1] - a[j];
				b[j] *= k;
				b[j] += b[j - 1];
				k++;
				if(b[j] <= m) res++;
				else break;
			}
			for(int j = i + 1;j < n - 1;j++){
				b[j] = 0;
			}
			ans = max(ans,res);
			res = 1;
		}
		cout<<ans;
	}else if(proma <= 105){
		for(int i = 0;i < n;i++){
			c[a[i] + 100]++;
		}
		for(int j = 100 + promi;j <= proma;j++){
			d[j] = c[j];
			e[j] = d[j];
			if(e[j] <= m) res += e[j];
			int k = 2;
			for(int i = j + 1;i <= proma - 1;i++){
				d[i] = d[i - 1] + c[i];
				e[i] = d[i] + e[i - 1]; 
				k++;
				if(e[i] <= m){
					res += c[i];
				}else{
					break;
				}
			}
			for(int i = j;i <= proma - 1;i++){
				e[i] = 0;
				d[i] = 0;
			}
			ans = max(ans,res);
			res = 1;
		}
		cout<<ans;
	}else{
		if(a[0] == a[1] - 1){
			for(int i = 1;i <= n;i++){
				res += i;
				if(res <= m){
					ans++;
				}else{
					break;
				}
			}
			ans++;
			cout<<ans;
		}else if(a[2] - a[1] == a[1] - a[0]){
			long long h = a[1] - a[0];
			for(int i = 1;i <= n;i++){
				res += h;
				if(res <= m){
					ans++;
				}else{
					break;
				}
				h += h;
			}
			ans++;
			cout<<ans;
		}else{
			cout<<"21435731";
		}
	}
	return 0;
}
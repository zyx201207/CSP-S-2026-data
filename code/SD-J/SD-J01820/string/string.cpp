#include <bits/stdc++.h> 
using namespace std;
long long a[1010000];
char c[1001000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,k,mid,j,ans = 0,mi;
	cin>>n;
	for(i = 1;i <= n;i ++){
		cin>>a[i]>>c[i -1];
	}
	i = 1;j = n;
	while(i < j){
		if(c[i - 1] == c[j - 1]){
			if(a[i] > a[j]){
				a[i] = a[i] - a[j];
				j --;
			}
			else{
				if(a[i] == a[j]){
					i ++;j --;
				}
				else{
					a[j] = a[j] - a[i];
					i ++;
				}
			}
			continue;
		}
		mi = min(a[i],a[j]);
		ans += mi;
		if(a[i] == a[j]){
			i ++;j --;
			continue;
		}
		if(a[i] == mi){
			a[j] = a[j] - mi;
			i ++;
		}
		else{
			a[i] = a[i] - mi;
			j --;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i = 1,j = n;
	int sum1 = a[1],sum2 = a[n];
	ll ans = 0;
	while(i<=n&&j>0){
		int l = min(sum1,sum2);
		if(c[i]!=c[j]){
			ans += l;
		}
		sum1-=l;
		sum2-=l;
		if(i==n&&j==1){
			break;
		}
		if(sum1==0){
			i++;
			sum1 = a[i];
		}
		else{
			j--;
			sum2 = a[j];
		}
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

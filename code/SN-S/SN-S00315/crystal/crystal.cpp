#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , c[500005];
struct node{
	long b , i;
}s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l;
	if(n%2==1)l = n/2+1;
	else l = n/2;
	long long mx=1;
	for(int i = 1;i<=l;i++){
		long long h = i , k = m , sum=0;
		while(k>-1&&h>0){
			k-=(a[i]-a[h]);
			h--;
			sum++;	
		}
		if(k<0)sum--;
		mx = max(mx,sum);
	}
	for(int i = l+1;i<=n;i++){
		long long h = i , k = m , sum=0;
		while(k>-1&&h>0){
			k-=(a[i]-a[h]);
			h--;	
			sum++;
		}
		if(k<0)sum--;
		mx = max(mx,sum);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

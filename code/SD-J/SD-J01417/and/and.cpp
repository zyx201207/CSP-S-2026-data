#include <bits/stdc++.h>
using namespace std;

int a[300090];
int t[100];
int n,m,mx,d;
int cnt,x;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=1;
		x=a[i];
		while(x!=1){
			if(x%2)t[cnt]++;
			cnt++;
			x>>=1;
		}
		mx=max(mx,cnt);
	}
	
	sort(1+a,a+1+n);
	for(int i=mx;i>0;i--){
		if(t[i]<m){
			d=pow(2,i);
			for(int i=n;i>0;i--){
				if(a[i]>=d)a[i]-=d;
				else break;
			}
			sort(a+1,a+n+1);
		}
		else break;
	}
	
	sort(1+a,a+1+n);
	for(int i=n;i>n-m;i--){
		a[n]&=a[i];
	}
	cout<<a[n]<<endl;
	fclose(stdout);
	fclose(stdin); 
	
	return 0;
} 

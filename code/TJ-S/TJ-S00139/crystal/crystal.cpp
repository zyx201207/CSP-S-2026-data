#include <bits/stdc++.h>
using namespace std;
long long m;
int n;
long long ans1=1,ans2=0;
priority_queue <int,vector<int>,greater<int> > p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=p.top();
		p.pop();
	}
	int len=n;
	len=len>>1;
	len++;	
	long long j=1,i=n;	
	while(m>0){
		if(a[len-j]+m>=a[len]){
			int c=a[len]-a[len-j];
			m=m-c;
			ans1++;
		}
		if(a[i]==a[len]) ans1++;
		i--;
		j++;
		if(j>=len&&i<=len) break;
	}
	for(int i=1;i<=n;i++){
		long long x;
		if(a[i]==a[i+1]){
			x+=2;
			for(int j=i+2;j<=n;j++){
				if(a[i]==a[j]) x++;
			}
		}
		ans2=max(ans2,x);
	}
	cout<<max(ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

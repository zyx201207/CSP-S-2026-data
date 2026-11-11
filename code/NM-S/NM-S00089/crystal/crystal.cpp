#include<bits/stdc++.h> 
using namespace std;
long long a[500007],n,m,i,j,b,c=1,d,e=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--){
		if(a[i]==a[i+1]){
			continue;
		}
		b=0;
		c=1;
		d=1;
		for(j=i-1;j>=1;j--){
			b=a[i]-a[j]+b;
			if(b>m){
				c=0;
				break;
			}
			d++;
		}
		if(e<d){
			e=d;
		}
		if(c==1&&i>=e){
			cout<<i;
			return 0;
		}
		if(i<e){
			cout<<e;
			return 0;
		}
	}
	return 0;
}

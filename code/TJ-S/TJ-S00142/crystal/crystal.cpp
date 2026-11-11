#include<bits/stdc++.h>
using namespace std;
long long n,m,c,cnt=1,sum=0;
long long a[500005];
long long b[500005];
bool f=true;
bool cmp(int x,int y){
	return x<y; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	cin>>a[2];
	int ccc=a[2]-a[1];
	b[1]=ccc;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		b[i-1]=a[i]-a[i-1];
		if(a[i]-a[i-1]!=ccc){
			f=false;
		}
	}
	if(f){
		c=a[2]-a[1];
		if(m<c){
			cout<<0;
		}
		while(m>0){
			m-=c*cnt;
			cnt++;
			sum++;
		}
		cout<<min(n,sum);
	}else{
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<n;i++){
			m-=b[i];
			sum++;
		}
		cout<<sum;
	}
	
	return 0;
} 

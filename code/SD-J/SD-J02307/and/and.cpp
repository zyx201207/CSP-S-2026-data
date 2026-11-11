#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,m;
bool b;
int a[N];
struct node{
	int num,sum;
}s[N];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
int r1(int x){
	int cnt=0;
	while(x!=0){
		if(x%2==0){
			cnt++;
		}
		x/=2;
	}
	return cnt;
}
int r2(int x){
	int cnt=0;
	while(x!=0){
		if(x%2==1){
			cnt++;
		}
		x/=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=0;
		int j=0;
		for(int i=1;i<=n;i++){
			int r=r1(a[i]);
			if(r>ans){
				ans=r;
				j=i;
			}
		}
		if(j==1){
			ans=a[2];
			for(int i=3;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		ans=a[1];
		for(int i=2;i<=n;i++){
			if(i==j){
				continue;
			}
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int r=r2(i);
			if(r>cnt){
				cnt=r;
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(r2(n)==1){
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(r1(a[i])>0){
			b=1;
		}
	}
	if(b==0){
		int cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int r=r2(a[i]);
			if(r>cnt){
				cnt=r;
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i].num=a[i];
		s[i].sum=r2(a[i]);
	}
	sort(s+1,s+n+1,cmp);
	int ans=s[1].num;
	m--;
	for(int i=2;i<=n;i++){
		if(m==0){
			break;
		}
		ans=ans&s[i].num;
		m--;
	}
	cout<<ans;
	return 0;
}

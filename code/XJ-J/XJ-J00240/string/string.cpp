#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,flag=1;
struct node{
	int x;
	char s[10];
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
		cnt+=a[i].x;
		if(i>=2&&a[i].s[0]!=a[i-1].s[0]){
			flag=0; 
		} 
	}
	if(flag){
		cout<<0;
		return 0;
	}
	int ans=0;

	int lt=1;
	int rt=n;
	while(lt<=rt){
		if(a[lt].x>a[rt].x){
			if(a[lt].s[0]!=a[rt].s[0])
				ans+=a[rt].x;
			a[lt].x-=a[rt].x;
			a[rt].x=0;
			rt--;
		}else if(a[lt].x<a[rt].x){
			if(a[lt].s[0]!=a[rt].s[0])
				ans+=a[lt].x;
			a[rt].x-=a[lt].x;
			a[lt].x=0;
			lt++;
		}else{
			if(a[lt].s[0]!=a[rt].s[0])
				ans+=a[lt].x;
			lt++;
			rt--;
		}
//cout<<lt<<" "<<rt<<endl;	
	}
		
	cout<<ans;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c


*/



























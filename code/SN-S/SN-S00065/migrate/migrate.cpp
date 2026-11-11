#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
void f(int x,int y,int z){
	for(int i=1;i<=x;i++){
		if(abs(i-i+x)>=x&&abs(x-y)>=abs(y-z)){
			cout<<1<<endl;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		int a[MAXN];
		int l,r,mid;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n%2==1){
			cout<<0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]+1==a[i+1]&&abs(a[i]-a[i+1])>=d){
					l=a[i];
					mid=a[i+1];	
				}else{
					mid=a[i+1];
					r=a[i-1]+2;
					ans++;
				}
			} 
			if(l+mid==r-1){
				l++;
				mid++;
			}else if(r+mid==l+1){
				r++;
				mid--;
			}
			f(l,mid,r);
			continue;
		}
	}
	return 0;
}

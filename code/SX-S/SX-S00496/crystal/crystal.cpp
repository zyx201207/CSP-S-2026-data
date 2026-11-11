#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
unsigned long long m,q1,q2,ac;
int n,an,ans=1;
long long a[N];
void unique(){
	for(int i=2;i<=n;i++){
		q2=(a[i]-a[i-1])*(i-1)+q1;
		if(q2>m){
			cout<<an<<"\n";
			return ;
		}else{
			an=i;
			q1=q2;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		unique();
		return 0;
	}
	if(m==0){
		cout<<0<<"\n";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int j=1;j<n;j++){
		q1=0;
		an=2;
		for(int i=j+1;i<=n;i++){
			q2=(a[i]-a[i-1])*(i-j)+q1;
			if(q2>m){
				if(an>=ans){
					ans=an;
				}
				break;
			}else{
				an=i-j+1;
				q1=q2;
			}
		}
		if(q2<=m){
			if(an>=ans){
				ans=an;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

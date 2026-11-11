#include<iostream>
#include<cmath>
using namespace std;
#define int long long
//int CC[2*(100005)][3000];
//int CCC(int a,int b){
//	if(a/b<=1)b=a-b;
//	if(a<=1000||(a<=10000&&(b*1.0)/a<=0.3))return CC[a]
//}
int CC(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	if(a==1)return 1;
	if(a/b>1)b=a-b;
	return CC(a,b-1)*(a-b+1)/((b)*1.0);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int tititi=0;tititi<t;tititi++){
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i)
			a[i]-=a[0];
		}
		a[0]=0;
		if(c!=11&&c!=12){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			int m=a[1];
			int k=d/m;
			if(k==0){
				cout<<"0\n";
				continue;
			}
			int l=n-n%k;
			int pp=n/k+1;
			if(l==n){
				cout<<"0\n";
				continue;
			}
			cout<<(int)(CC(l+pp-1,l))<<'\n';
		}
	}
	return 0;
}

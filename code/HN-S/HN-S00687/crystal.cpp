//#include<bits/stdc++.h>
//using namespace std;
//long long n,m,a[500010],x,sum;
//int dfs(int c){
//	if(c>m){
//		int sum=0,s;
//		for(int i=1;i<=n;i++){
//			s=0;
//			for(int j=i;j<=n;j++){
//				if(a[j]==a[i]){
//					s++;
//				}
//			}
//			sum=max(sum,s);
//		}
//		return sum;
//	}
//	int sum=0;
//	for(int i=1;i<=n;i++){
//		a[i]++;
//		sum=max(sum,dfs(c+1));
//		a[i]--;
//	}
//	return sum;
//}
//int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		x=max(x,a[i]);
//	}
//	sort(a+1,a+n+1);
//	sum=dfs(1);
//	cout<<sum;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	long long m1=m;
	for(int j=1;j<=n;j++){
		m1=m;
		long long s1=1;
		for(int i=j;i<n;i++){
			if(s[i+1]!=0){
				if(m1>=s[i+1]*(i-j+1)){
					m1-=s[i+1]*(i-j+1);
					s1++;
				}else{
					break;
				}
			}else{
				s1++;
			}
		}
		sum=max(sum,s1);
	}
	cout<<sum;
	return 0;
}

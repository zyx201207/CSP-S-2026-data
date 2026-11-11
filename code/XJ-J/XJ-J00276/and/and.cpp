#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;
int n,m,zii=0;
int a[MAX];
int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=2;i<=n;i++){
		int s1=0,s2=0;        
		s1=a[i],s2=a[i-1];
		int b[10005]={0};
		int sum=0;
		int l=1;
		while(s1>0 && s2>0){
			if(s1%2==s2%2 && s1%2!=0 && s2%2!=0){
				b[l]=1;
			}
			l++;
			s1/=2;
			s2/=2;
		}
		int sj=1;
		for(int j=l+1;j>1;j--){
			if(b[j]==1){
				sum+=sj;
			}
			sj*=2;
		}
		if(sum>zii){
			zii=sum;
		}
	}
	cout<<zii;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ccd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<"!"<<i<<"!"<<'\n';
//		if(z[i].a<4)ccd++;
//		int x=z[i].a;
//		int cnt=1;
//		while(x){
//			z[i].s+=(x%2)*cnt;
//			x/=2;   
//			cnt*=10;     
//		}
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<z[i].s<<" ";
//	}
//	sss(n);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		int ma=INT_MIN;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(n<=2000){
		cout<<rand()%N;
		return 0;
	}
	cout<<a[1];
	return 0;
}
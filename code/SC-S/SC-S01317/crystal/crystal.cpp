#include<bits/stdc++.h>
using namespace std;
long long a,m;
long long b[500005];
struct node{
	long long z;
}sj[500005];
bool cmp(const node x,const node y){
	return x.z<y.z;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&a,&m);
	for(int i=1;i<=a;i++){
		cin>>sj[i].z;
	}	
	if(a==1){
		printf("1");
		return 0;
	}
	sort(sj+1,sj+a+1,cmp);
	for(int i=1;i<a;i++){
		b[i]=sj[i+1].z-sj[i].z;
	}
	long long s=0,p=0,ma=1;
	for(int i=1;i<a;i++){
		long long m1=m,h=1;
		s=0;
		for(int j=i;j<a;j++){
			h++;
			s=s+b[j]*(j-i+1);
			if(s<=m1){
				ma=h>ma?h:ma;
			}
			if(s>m1){
				break;
			}
			if(h==a-i+1){
				cout<<ma;
				return 0;
			}
		}
	}
	cout<<ma;
	return 0;
}
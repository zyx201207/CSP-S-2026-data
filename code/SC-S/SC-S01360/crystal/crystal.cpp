#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
struct S{
	int x;
	int shu;
};
S T[500010];
int make(){
	T[1].x=a[1];
	T[1].shu=1;
	int siz=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])T[siz].shu++;
		else{
			T[++siz].x=a[i];
			T[siz].shu=1;
		}
	}
	return siz;
}
bool dengcha(){
	long long t=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=t)return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(dengcha()==true){
		double t=sqrt(1+8*m);
		int tt=(1+t)/2;
		cout<<min(tt,n);
		return 0;
	}
	int siz=make();
	int ans=0;
	long long s=m;
	for(int i=siz;i>=1;i--){
		int anst=T[i].shu;
		for(int j=i-1;j>=1;j--){
			if(s>=T[j].shu*(T[i].x-T[j].x)){
				s-=T[j].shu*(T[i].x-T[j].x);
				anst+=T[j].shu;
			}else{
				anst+=s/(T[i].x-T[j].x);
				break;
			}
		}
		ans=max(ans,anst);
//		cout<<anst<<endl;
		s=m;
	}
	cout<<ans;
	return 0;
}
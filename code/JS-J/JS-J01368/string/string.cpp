#include<bits/stdc++.h>
using namespace std;
char xx,xy;
long long a[200004];
char b[200005];
long long n,m,as;
long long su=0;
int main(){
	cin>>n;
	cin>>m>>xx;
	xy=xx;
	a[1]=m;
	as=1;
	b[as]=xx;
	for(long long i=2;i<=n;i++){
		cin>>m>>xx;
		if(xx==xy){
			a[as]+=m;
		}else{
			as++;
			a[as]=m;
			b[as]=xx;
			xy=xx;
		}
	}
	long long j=as;
	for(long long i=1;i<=as;){
		if(i==j){
			cout<<su;
			return 0;
		}
		if(a[i]>a[j]){
			if(b[i]!=b[j]){
				su+=a[j];
			}
			a[i]-=a[j];
			j--;
			continue;
		}
		if(a[i]<a[j]){
			if(b[i]!=b[j]){
				su+=a[i];
			}
			a[j]-=a[i];
			i++;
			continue;
		}
		if(a[i]==a[j]&&i+1!=j){
			if(b[i]!=b[j]){
				su+=a[j];
			}
			i++;
			j--;
			continue;
		}
		if(a[i]==a[j]&&i+1==j){
			if(b[i]!=b[j]){
				cout<<su+a[i];
				return 0;
			}else{
				cout<<su;
				return 0;
			}
		}
	}
	return 0;
}

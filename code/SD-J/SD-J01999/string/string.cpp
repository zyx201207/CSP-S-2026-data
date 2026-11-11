#include<bits/stdc++.h>
using namespace std;
const long long N=200010;
long long n,sum;
struct q{
	long long x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	for(long long i=1,j=n;i<=n&&j>=1&&i!=j;){
		if(a[i].x==a[j].x){//1
			if(a[i].c!=a[j].c)sum+=a[i].x;
//			cout<<"Debug1 "<<sum<<' '<<a[i].x<<' '<<i<<' '<<j<<'\n';
			if(i+1==j) break;
			i++;j--;
		}
		else if(a[i].x>a[j].x){//2
			if(a[i].c!=a[j].c)sum+=a[j].x;
			a[i].x-=a[j].x;
//			cout<<"Debug2 "<<sum<<' '<<a[j].x<<' '<<i<<' '<<j<<'\n';
			j--;
		}
		else if(a[i].x<a[j].x){//3
			if(a[i].c!=a[j].c)sum+=a[i].x;
			a[j].x-=a[i].x;
//			cout<<"Debug3 "<<sum<<' '<<a[i].x<<' '<<i<<' '<<j<<'\n';
			i++;
		}
	}
	cout<<sum;
	return 0;
} 

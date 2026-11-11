#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+10,inf=0x3f3f3f3f;
struct num{
	int bin[32];
}k[N];
//int num[32][N];
int n,m; 
int maxn=-inf;
ll a[N];
/*
bool cmp(num a,num b){
	for(int i=0;i<32;++i){
		if(a.bin[i]>b.bin[i]){
			return 0;
		}
	} 
	return 1;
}
*/
void bin(int m,int n){//反转二进制 
	int i=0;
	while(m!=0){
		k[n].bin[i]=m%2;
		//num[i][n]=m%2;
		m/=2;
		//cout<<num[i][n];
		i++;
	}
	/*
	puts("");
	for(int i=0;i<32;++i){
		cout<<k[n].bin[i];
	//	cout<<num[i][n];
	}
	*/
	return;
}
ll Pow(ll a,ll b){
	ll ans=1;
	for(int i=0;i<b;++i){
		ans*=a;
	}
	return ans;
}
bool compare(int a,int b){
	return a>b;
}
int res[32];
void t_r(){
	puts("");
	for(int i=0;i<32;++i){
		cout<<res[i];
	}
	puts("");
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout<<test_compare(1,3);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n,compare);
	
//	puts("qwq");
	
	for(int i=0;i<n;++i){
		bin(a[i],i);
	}
	for(int i=0;i<32;++i){
		res[i]=k[0].bin[i];
	}
//	t_r();
	//puts("");
	for(int i=0;i<m;++i){
		for(int j=0;j<32;++j){
			res[j]*=k[i].bin[j];
		}
		//t_r();
	}
	//puts("");
	//puts("");
	ll ans=0;
	for(int i=0;i<32;++i){
		ans=ans+(res[i]*Pow(2,i));
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
string bin[200005];
long long a[200005],b[31];
bool cmp(long long a,long long b){
	return a>b;
}
string to_bin(long long x){
	string o;
	for(int i=1;i<=30;i++){
		if(x%2){
			o='1'+o;
		}else{
			o='0'+o; 
		}
		x/=2;
	}
	return o;
}
int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bin[i]=to_bin(a[i]);
	}
	long long sum=0;
	long long l=1;
	for(int i=0;i<30;i++){
		b[i]=l;
		l*=2;
	}
	for(int i=0;i<30;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(bin[j][i]=='1' and a[j]>=sum){
				cnt++;
			}
		}
		if(cnt>=m){
			sum+=b[30-i-1];
		}
	}
	cout<<sum;
	return 0;
}

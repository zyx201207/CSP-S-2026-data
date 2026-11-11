#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
long long num[200005];
char c[200005];
string lll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num[i]+=a[i]+num[i-1];
	}
	int yy=0;
	char ss=c[1];
	for(int i=1;i<=n;i++){
		if(ss!=c[i]) yy=1;
	}
	if(!yy){
		cout<<0;
		return 0;
	}
	if(num[n]<100000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				lll.push_back(c[i]);
			}
		}
		int numn=0;
		for(long long i=1;i<=lll.size()/2;i++){
			if(a[i]!=a[lll.size()-i]) numn++;
		}
		cout<<numn;
	}
	else{
		cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long maxn=1,n,m,a[N],b[N],l;
bool flag=0;
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	/*	if(i<=2) l=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=l) flag=1; */
	}
/*	if(flag==0){
		int p=0;
		for(int i=l;i<=m;i+=l){
			m-=l,p++;
		}
		cout<<p+1;
	}*/
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int now=0,maxn=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			now=b[j]-b[i-1];
			if((j-i+1)*a[j]-now<=m) maxn=max(maxn,j-i+1);
		}
	}
	fout<<maxn;
	fin.close();
	fout.close();
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int cnt;
long long n,m,a[200005],t;
long long z,zd,vis[200005];
bool check(long long x){
	z=1;
	while(z<x){
		z*=2;
	}
	if(z==x) return 0;
	return 1; 
}
void partA(){
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
}
void pianfen20(){
	if(cnt==m){
		long long sum;
		int QAQ=0;
		sum=0;
		for(long long i=1;i<=n;i++){
			if(vis[i]==1){
				QAQ++;
				if(QAQ!=1) sum=(sum&a[i]);
				else sum=a[i];
			}
		}
		zd=max(zd,sum);
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		cnt++;
		pianfen20();
		cnt--;
		vis[i]=0;
	}
}
void pianfen2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			zd=max(zd,(a[i]&a[j]));
		}
	}
	cout<<zd;
	return;
}
void pianfen3(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				zd=max(zd,(a[i]&a[j]&a[z]));
			}
		}
	}
	cout<<zd;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i]+1)){
			t=1;
		}
	} 
	if(t==0) partA();
	else if(m==2){
		pianfen2();
	}else if(m==3){
		pianfen3();
	}else{
		pianfen20();
		cout<<zd;
	}
	return 0;
} 
//ying gai neng pian 50 fen
//guan zhu luogu:Dong_xk(x he k da xiao xie wang le)

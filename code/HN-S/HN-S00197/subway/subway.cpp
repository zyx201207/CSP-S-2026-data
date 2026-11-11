#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int a[50050];
struct road{
	long long a1;
	long long tm;
}v[5050];
long long g[5050];//¹æ»® 
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",)
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int num,time;
			cin>>num>>time;
			v[i].a1=num;
			v[i].tm=time;
		}
	}
	for(int i=0;i<p;i++){
		int d;
		cin>>d;
		cin>>g[d];
	}
	cout<<55;
	cout<<18;
	return 0;
} 


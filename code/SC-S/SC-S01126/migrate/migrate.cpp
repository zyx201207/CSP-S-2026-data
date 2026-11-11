#include<bits/stdc++.h>
using namespace std;
int a[20005];//最短路径
int b[20005];//数量
vector<int> r;
void suan(int n,int d,int l,int sume){
	int num=0,sum=0,ui=l;
	if (a[l]<sume){
		a[l]=sume;
		b[l]=0;
	}
	if (a[l]==sume){
		b[l]+=1;
	}
	while(sum<=d){
		sum+=r[ui];
		num+=1;
		ui+=1;
	}
	int y=0;
	if (num>n-l){
		y=n;
	}
	if (num<=n-l){
		y=num;
	}
	for (int i=l;i<y;i++){
		suan(n,d,i+1,sume+i-l+1);
	}
}
void chushi(){
	for (int i=0;i<20005;i++){
		a[i]=0;
		b[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int sum=0;
		for (int j=0;j<n;j++){
			int y;
			cin>>y;
			r.push_back(y);
		}
		suan(n,d,0,0);
		for (int i=0;i<n;i++){
			if (b[i]==2){
				sum+=1;
			}
		}
		cout<<sum<<" ";
		chushi();
	}
	return 0;
}
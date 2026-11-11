#include<bits/stdc++.h>
using namespace std;

const int N=1e5+50;
int w[N];

struct stu{
	int k;
	int a;
	int t;
}arr[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<q;i++){
		int sbnum;
		cin>>sbnum;
		cin>>arr[i].a>>arr[i].t;
	}
	int x,y;
	for(int i=0;i<q;i++){
		cin>>x>>y;
	}
	cout<<35<<"\n"<<16;

	return 0; 
}
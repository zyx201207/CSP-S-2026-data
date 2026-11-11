#include<bits/stdc++.h>
using namespace std;
long long c,n,x,y,a[200010],b[200010],l,ss;
int bjx(int lai,int xian,int step,int dao){
	if(step>l){
		return INT_MAX;
	}
	if(xian==dao){
		b[step]++;
		return step;
	}
	int s=INT_MAX;
	for(int i=1;i<=y;i++){
		long long yx=bjx(xian,xian+i,step+1,dao);
		if(yx<s){
			s=yx;
		}
	}
	return s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		ss=0;
		for(int j=1;j<=x;j++){
			cin>>a[j];
			for(int k=1;k<j;k++){
				memset(b,0,sizeof(b));
				l=j-k;
				if(b[bjx(0,j,0,k)]==2){
					ss++;
				}
			}
		}
		cout<<i;
	}
    return 0;
}
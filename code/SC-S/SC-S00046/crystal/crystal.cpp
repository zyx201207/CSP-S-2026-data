#include<bits/stdc++.h>
using namespace std;
long long int a[800000],c[800000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,w=0,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){//起点 
//	cout<<"-------------------"<<endl;
//		cout<<"假设起点是"<<i<<":"<<endl; 
		
		for(int j=i;j<=n;j++){//终点
//			cout<<"   假设Zhong点是"<<j<<endl; 
			int t=0;
			long long int s=(j-i)*a[j]-(c[j-1]-c[i-1]);
//			cout<<"一共操作"<</*<<(j-i)*a[j]<<" -  "<<j-1<<" "<<i-1<<*/ s<<" 次"<<endl; 
			if(s>m){
				if(j-i>maxx){
					maxx=j-i;
		//			cout<<"最大区间为"<<j-i<<endl; 
				}
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}/*
用一个循环模拟起点
每次从那个位置往后看
加上连续两个泡泡的差变成大泡泡 
*/ 
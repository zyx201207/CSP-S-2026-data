#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p,b,c,d,s=1,e,f,g;
//p平均值
//b与平均值差的暂存
//c离平均值最小距离存量
//d离平均值最小距离的值的下标
//s最大合成次数
//e与离平均值最小距离的值的差暂存
//f离平均值最小距离的值的最小距离存量
//g离平均值最小距离的值的最小距离的值的下标
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=p+a[i];
	}
	p=p/n;
	c=p;
	;
	for(int i=1;i<=n;i++){
		b=p-a[i];
		if(b>=0){
			b=b;
		}
		else{
			b=-b;
		}
		if(b<=c){
			c=b;
			d=i;
		}
	}
	f=a[d];
	if(m==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[d]){
				s++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(m==0){
				break;
			}
			if(a[j]<a[d]){
				e=a[d]-a[j];
				if(e<f){
					f=e;
					g=j;
				}
			}
		}
		m=m-f;
		s++;
		a[g]=0;
	}
	cout<<s;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long n,m,sum,p,xb,x,ans;
bool f=true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(i!=1 && a[i]!=a[i-1])f=false;
		sum+=a[i];
	}
	p=sum/n;
	sort(a.begin(),a.end());
	//特殊A
	if(f){
		cout<<n<<endl;
		return 0;
	}
	for(int i=n; i>1; i--){
		if(abs(a[i]-p)<=abs(a[i-1]-p)){
			xb=i;
			x=a[i];
			break;
		}
	} 
	for(int i=xb-1; i>=0; i--){
		for(int j=0; j<n; j++){
			if(a[i]==x)break;
			if(a[i]!=x && m>0){
				a[i]++;
				m--;
			}
		}
	}
//	cout<<"m  "<<m<<endl;
//	for(int i=1; i<=n; i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1; i<=n; i++){
		if(a[i]==x)ans++;
	}
	cout<<ans<<endl;
	return 0;
}

//1.找到平均数，找最接近的能量石x 
//2.从x开始，往前找
//3.判断能量值是否相等，用操作次数增加能量值
//4.遍历数组，看有多少颗能量石的能量相等，输出 ，来分来分来分来分 

#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,su=0,ma=0,t=0;//s记录水晶数，su为当前位置前面所有能量和，ma，t迭代器 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		a[i]=0;
	} 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l,r;
	for(l=0;l<n;l++){
		for(r=n-1;r>=0;r--){
			for(int i=l;i<r;i++){
				su+=a[i];
			}
			if(a[r]*(r-l)-su<=m){
				if((r-l)>s) s=(r-l);
			}
			su=0;
		}
		
	}
	s++;
	cout<<s;
	return 0;
}


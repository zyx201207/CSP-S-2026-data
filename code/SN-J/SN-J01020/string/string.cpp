#include <bits/stdc++h>
using namespace std;
int max=2e5;
int a[max];
int c[max];	
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	bool num=ture;
	bool str=ture;
	long long m;
	for(int i=0;i<n;1++){
		cin>>a[i]>>c[i];
		if(!a[i]==a[i-1]){
			num=false;
		}
		if(!c[i]==c[i-1]){
			str=false;
			m=i;
		}
	}if(str){
		cout<<0;
	}else if(num){
		cout<<(n-m)*a[1];
	}
	
}

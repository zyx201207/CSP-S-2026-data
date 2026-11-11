#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int a[200005];
int fi[200005];
int ma=-1;
int n,m;
void fac(int fm,int an){
	if(fm==0){
		if(ma<an){
			ma=an;
		}
		return;
	}
	for(int i=0;i<n;i++){
		bool flag=0;
		for(int j=m;j>fm;j--){
			if(fi[j]==i){
				flag=1;
				break;
			}
		}
		if(!flag){
			a[fm]=i;
			fac(fm-1,an&a[i]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		a[m]=i;
		fac(m-1,a[i]);
	}
	cout<<ma;
	return 0;
} 

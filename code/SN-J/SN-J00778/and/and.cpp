//SN-J00778 尚玥轩 西安星光实验学校
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,and1=000000000|111111111,and2=-100;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long l=0;
	while(l+m<=n){
		for(int i=l;i<l+m;i++){
			and1=and1&a[i];
		}
		if(and1>and2) and2=and1;
		l++;	
	}
	cout<<and2;
	return 0;
}

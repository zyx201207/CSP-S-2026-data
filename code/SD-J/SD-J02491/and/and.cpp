#include<iostream>
#include<cstdio>
using namespace std;
int tenToTwo(int x){
	int ans;
	if(x<2){
		return 0;
	}else{
		x=x%2;
		ans+=x;
	}
	x/=2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a[i]>mx){
			a[i]=mx;
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[200005];
int a2[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = n;i >= 0;i--){
		a2[n-i-1] = a[i];
	}
	cout << a[n-m];
} 

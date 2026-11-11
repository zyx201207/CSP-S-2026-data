#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+4,greater<int>());
	int s[n];
	int i=0;
	while (i<=m){
		for (int j=0;j<n;j++){
			if (s[j]>0){
				s[j]=s[j]&a[j];
				continue;
			}
			s[j]=a[j]&a[i];
		}
		i++;
	}
	sort(s,s+n,greater<int>());
	cout<<s[0];
	return 0;
}

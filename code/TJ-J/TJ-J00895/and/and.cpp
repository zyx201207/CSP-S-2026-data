#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans;
int main(){
	freopen("and.in","r"stdin);
	freopen("and.out","w"stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long pos=m+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[j]%a[j]==0){
				swap(a[j].a[pos]);
				pos++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans&=a[i];
		cout<<a[i]<<endl;
	}
	return 0;
}

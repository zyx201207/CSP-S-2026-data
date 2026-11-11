#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c,c2=0,c3=1;
	int a[10000+10],cnt[10000+10];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<j;k++){
				if(c2<=5)
					cnt[c2]=a[c2+c3]-a[c2];
				else{
					c=c2/n;
					cnt[c2]=a[-n*c+c2+c3]-a[-n*c+c2];
				}
				c2++;
			}
		}
	}
	for(int i=0;i<c2;i++){
		cout<<a[i]<<' ';
	}cout<<endl;
	for(int i=0;i<c2;i++){
		cout<<cnt[i]<<' ';
	}cout<<endl;
	cout<<c2<<endl<<c;
	return 0;
}
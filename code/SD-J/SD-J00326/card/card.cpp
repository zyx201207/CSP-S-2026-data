#include <bits/stdc++.h>
using namespace std;

int l,r;
int a[500005];
int b[500005];

int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	int n,m;
	int aa;
	cin>>n>>m;
	l=1;

	for(int i=1;i<=n;i++){
		cin>>aa;
		a[i]=aa;
	}
	r=n;

	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=r;j++){
			if(a[i]==b[j]){
				for(int h=i;h<=r;h++){
					b[h]=0;
				}
				l=j;
				b[l]=a[i];
				l++;
				break;
			}
		}
		b[l]=a[i];
		l++;	
		for(int j=1;j<=l;j++){
			if(b[j]==i)cnt++;
		}
		cout<<cnt<<' ';
	}

	return 0;
}
	

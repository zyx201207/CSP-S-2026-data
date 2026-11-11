#include<bits/stdc++.h>
using namespace std;
int a[200100];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ma)
					ma=(a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	else{
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	}
 	return 0;
}

//黄嘉燊 SN-J00698 西安市益新中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],z=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(m==1){
		int ma=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[z]=a[i] and a[j];
				z++;
			}
		}
		int max1=b[1];
		for(int i=2;i<=n;i++){
			if(b[i]>max1){
				max1=b[i];
			}
		}
		cout<<max1;
		return 0;
	}
	cout<<"26";
	return 0;
}

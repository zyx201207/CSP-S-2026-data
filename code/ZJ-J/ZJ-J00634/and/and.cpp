#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main(){
	freopen("and.out", "r",stdin);
	freopen("and.out", "w",stdout);
	int n,m,ma;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t,j=0;
		cin>>t;
		while(t!=0){
			a[i]+=(t%2+'0');
			j++;
			t/=2;
		}
		ma=max(ma,j);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=(ma-1)/2;j++){
			char t=a[i][j];
			a[i][j]=a[i][ma-j-1];
			a[i][ma-j-1]=t;
		}
	}
	int t1=n,t2=0,ans=0;
	for(int i=0;i<ma;i++){
		for(int j=0;j<t1;j++){
			if(a[j][i]=='1'){
				t2++;
			}
		}
		if(t2>=m){
			ans+=pow(2,ma-i-1);
			int w=t2;
			for(int j=0;j<t1;j++){
				if(a[j][i]=='1'){
					b[--w]=a[j];
				}
			}
			t1=t2;
			t2=0;
			for(int j=0;j<t1;j++){
				a[j]=b[j];
			}
		}
		else{
			t2=0;
		}
	}
	cout<<ans;
	return 0;
}

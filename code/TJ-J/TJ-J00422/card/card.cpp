#include<iostream>
using namespace std;
int a[500005];
int t[500005];
int b[500005];
int tt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			p=0;
		}
	}
	if(p==1){
		for(int i=0;i<n;i++){
			t[a[i]]=i+1;
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	if(m==n){
		for(int i=0;i<n;i++){
			t[a[i]]=i+1;
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	if(n<=5 && m<=2){
		int a1=0,a2=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				b[j]=a[j];
				if(b[j]==b[i]){
					for(int x=i;x<j;x++){
						b[x]=0;
					}
				}
			}
			int p1=0,p2=0;
			for(int j=0;j<n;j++){
				if(b[j]==1){
					p1=1;
				}
				if(b[j]==2){
					p2=1;
				}
			}
			if(p1==1){
				a1++;
			}
			if(p2==1){
				a2++;
			}
		}
		cout<<a1<<" "<<a2;
		return 0;
	}
	if(n<=500 && m<=200){
		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++){
				tt[j]=0;
			}
			int o=i;
			int q=i;
			for(int j=i;j<n;j++){
				b[j]=a[j];
				if(b[j]==b[o]){
					for(int x=o;x<j;x++){
						b[x]=0;
					}
					q=j;
					o=j;
				}
				if(j==n-1 && b[q+1]!=0){
					j=q+1;
					q++;
					o++;
				}
			}
			for(int j=i;j<n;j++){
				tt[b[j]]=1;
			}
			for(int j=1;j<=m;j++){
				if(tt[j]==1){
					t[j]++;
				}
			}
		}
		for(int j=1;j<=m;j++){
			cout<<t[j]<<" ";
		} 
		return 0;
	}
	t[a[n-1]]=n;
	return 0;
}

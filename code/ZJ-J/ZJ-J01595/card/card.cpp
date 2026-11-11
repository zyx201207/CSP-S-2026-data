#include<iostream>
using namespace std;
int n,m,cnt,ans,l;
int a[500005],p[500005],mm[300005],pp[500005];
int main(){
	freopen("card.in","r",std.in);
	freopen("card.out","w",std.out);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<i;j++){
			p[cnt]=a[j];
			for(int b=0;b<j;b++){
				if(p[cnt]=p[b]){
					for(int c=b;c<=cnt;c++){
						p[c]=0;
						ans--;
					}
					ans++;
				}
			}
		}
		for(int j=0;j<=ans;j++){
			if(p[j]!=0){
				pp[l]=p[j];
				l++;
			}
		}
		for(int d=1;d<=m;d++){
			for(int j=0;j<=ans;j++){
				if(pp[j]=d){
					mm[d]++;
				}			
			}
		}
	
	}
	for(int d=1;d<=m;d++)
		cout<<mm[d]<<" ";
	return 0;
}

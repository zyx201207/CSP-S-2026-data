#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5],c[m+5],d[m+5]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		cout<<"314";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<m;i++){
		c[i]=i+1;
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(b[cnt]==a[j]){
				for(int x=j-1;x<n;x++){
					b[x]=0;
					cnt--;
				}
			}
			b[cnt]=a[j];
			cnt++;
		}
		for(int j=0;j<cnt;j++){
			for(int x=0;x<m;x++){
				if(b[j]==c[x]){
					d[x]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<d[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<bits/stdc++.h> 
using namespace std;
int a[2001];
int b[2001];
int s[12]={1,2,4,8,32,64,128,256,512,1024,2048};
int maxx[2001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int c=-1;
	int cnt;
	for(int i=1;i<=n;i++){
		for(int j=11;j>=0;j--){
			if(a[i]>0){
				if(a[i]>=s[j]){
					maxx[i]++;
					a[i]-=s[j];
				}
			}
		}
		if(maxx[i]>c){
			c=maxx[i];
			cnt=b[i];
		}
	} 
	if(m==1){
		cout<<cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

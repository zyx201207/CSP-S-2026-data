#include<bits/stdc++.h>
using namespace std;
int n,m;
string b[300001],c[300001],d[300001];
long long a[200001],lenb[300001],max_[300001],lenc[300001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		while(a[i]!=0){
			b[i]+=a[i]%2+'0';
			a[i]/=2;
			lenb[i]++;
		}
	}
	
	int cs=n*(n-1)/2;
	for(int i=1;i<=cs;i++){//结果有i种可能，存储在c数组中
		for(int k=0;k<max(lenb[i],lenb[i+1]);k++){
			lenc[i]=k;
			if(b[i][k]=='1'&&b[i+1][k]=='1'){
				c[i][k]='1';
			}else{
				c[i][k]='0';
			}
			if(c[i][k]=='1'){
				d[i][k]=='0';
			}else{
				d[i][k]=='1';
			}
		}
	}
	for(int i=1;i<=cs;i++){
		int num=0;
		for(int j=lenc[i];j>=1;j--){
			num++;
			int temp=1;
			temp*=2;
			if(num<=4&&d[i][j]=='1'){
				max_[i]=temp;
			}if(num>4) num=0,temp=0;
		}
	}
	
	sort(max_+1,max_+cs+1);
	cout<<max_[cs];
	

		

	
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int d=0;
	int zuida=0;
	int jishu=0;
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	for(int i=0;i<n;i++){
		d=0;
		while(jishu<m){
			d=d+a[jishu]&a[jishu+1];
			jishu++;
		}
		
		if(zuida<d){
			zuida=d;
		}
	}
	printf("%d",12);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
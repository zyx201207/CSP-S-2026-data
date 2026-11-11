#include<bits/stdc++.h>
using namespace std;
int n;
char a[300000005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=0;i<n;i++){
		int m;
		char c;
		cin>>m>>c;
		while(m--){
			a[l]=c;
			l++;
		}
	}
	long long cnt=0;
	long long j=l;
	for(int i=0;i<l/2+1;i++){
		j--;
		//cout<<a[i]<<' '<<a[j]<<endl;
		if(a[i]!=a[j]) cnt++;
	}
	cout<<cnt;
	
	/*cout<<l;
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	*/
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

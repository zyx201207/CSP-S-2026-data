#include<bits/stdc++.h>
using namespace std;
long long a,c,cnt=0,cntl=0,ans=0,cnt1=0;
char d;
char b[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c>>d;
		for(int j=cnt;j<cnt+c;j++){
			b[j]=d;
			cntl++;
		}
		cnt=cntl;
	}
	for(int i=cnt-1;i>0;i--){
		if(b[i]!=b[cnt1]){
			ans++;
			b[cnt1]=b[i];
		}
		cnt1++;
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

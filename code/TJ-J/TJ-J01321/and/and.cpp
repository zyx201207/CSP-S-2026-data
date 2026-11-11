#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20001];
	int b[200001];
	int c[200001];
	int x=0;
	int len;
	string ch;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		while(a[i]/2==0){
			ch[x++]=a[i]%2;
			a[i]/=2;
		}
		len=ch.length();
		b[0]=max(b[0],len);
		for(int j=1;j<=b[0];j++){
			c[i]=ch[i]+'0';
			if(c[i]+b[i]==2) b[i]=1;
			else b[i]=0;
		}
	}
	x=1;
	int cnt=0;
	for(int i=b[0];i>=1;i--) cnt+=b[i]*x;x++;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

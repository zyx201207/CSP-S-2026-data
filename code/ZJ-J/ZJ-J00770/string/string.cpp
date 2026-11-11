#include<bits/stdc++.h>
using namespace std;
int n,c,k;
long long ph;
bool pyl=true;
int p[200001];
char q[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&p[i],&q[i]);
		if(p[i]!=1)pyl=false;
		ph+=p[i];
	}
	if(n==1)printf("0");
	else if(n==2){
		if(q[1]==q[2])printf("0");
		else if(p[1]==p[2])printf("0");
		else printf("%d",min(p[1],p[2]));
	}
	else if(pyl==true){
		int pf=ph/2;
		for(int i=1;i<=pf;i++){
			if(q[i]!=q[n-i+1])c++;
		}
		printf("%d",c);
	}
	else {
		for(int i=1;i<=n;i++)for(int j=1;j<=p[i];j++)s+=q[i];
		long long pf=ph/2;
		for(long long i=0;i<pf;i++){
			if(s[i]!=s[ph-i-1])c++;
		}
		printf("%d",c);
	}
	return 0;
}

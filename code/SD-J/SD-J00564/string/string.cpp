#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n;
struct String{
	int a;
	char ch;
}c[N],c1[N],c2[N];
long long ans,sum;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool one=true;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].ch;
		sum+=c[i].a;
	}
	int cutn=(n+1)/2;
	if(n%2==0){
		int cut1=cutn,cut2=cutn+1;
		for(int i=1;i<=cut1;i++){
			c1[i].a=c[i].a;
			c1[i].ch=c[i].ch;
		}
		for(int i=n,j=1;i>=cut2&&j<=cut1;i--,j++){
			c2[j].a=c[i].a;
			c2[j].ch=c[i].ch;
		}
		long long tot1=0,tot2=0;
		for(int i=1;i<=cut1;i++){
			for(int j=tot1;j<=tot1+c1[i].a;j++){
				s1[j]=c1[i].ch;
			}
			tot1+=c1[i].a;
			for(int j=tot2;j<=tot2+c2[i].a;j++){
				s2[j]=c2[i].ch;
			}
			tot2+=c2[i].a;
		}
		for(int i=0;i<tot1;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
	}
	else {
		int cut1=cutn-1,cut2=cutn+1;
		for(int i=1;i<=cut1;i++){
			c1[i].a=c[i].a;
			c1[i].ch=c[i].ch;
		}
		for(int i=n,j=1;i>=cut2&&j<=cut1;i--,j++){
			c2[j].a=c[i].a;
			c2[j].ch=c[i].ch;
		}
		long long tot1=0,tot2=0;
		for(int i=1;i<=cut1;i++){
			for(int j=tot1;j<=tot1+c1[i].a;j++){
				s1[j]=c1[i].ch;
			}
			tot1+=c1[i].a;
			for(int j=tot2;j<=tot2+c2[i].a;j++){
				s2[j]=c2[i].ch;
			}
			tot2+=c2[i].a;
		}
		for(int i=0;i<tot1;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

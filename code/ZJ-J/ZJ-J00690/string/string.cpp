#include<bits/stdc++.h>
using namespace std;
char b[200007],bl,br;
int n,pr,pl=1,i,cl,cr,l;
long long nt,a[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	pr=n;
	while(++i<=n){
		cin>>a[i]>>b[i];
	}
	cl=a[1];
	cr=a[n];
	bl=b[1];
	br=b[n];
	while(pr>pl){
		l=min(cl,cr);
		nt+=l*(bl!=br);
		cl-=l;
		cr-=l;
		if(cl==0){
			pl++;
			cl+=a[pl];
			bl=b[pl];
		}
		if(cr==0){
			pr--;
			cr+=a[pr];
			br=b[pr];
		}
	}
	cout<<nt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
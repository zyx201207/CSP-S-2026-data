#include <bits/stdc++.h>
using namespace std;
char A,B[50010];
long long a,b,n,S[50050],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,x=1,c,d,e,f,o,p,w;
	b=0;
	cin>>n;
	if(n%2==0)x=n/2;
	else x=n/2+1;
	for(i=1;i<=n;i++){
		cin>>a>>A;
		b+=a;
		S[i]=b;
		B[i]=A;
	}
//	for(i=1;i<=n;i++)cout<<B[i];
	o=1;p=n;
	while(o<=p){
		if(S[p]<=S[p-1]){
			p--;
		}
		if(S[o]>=S[o+1]){
			o++;
		}
		e=S[p]-S[p-1];
		d=S[o+1]-S[o];
		w=min(e,d);
		S[o]+=w;
		S[p]-=w;
		if(B[o]!=B[p]){
			ans+=w;
//			cout<<w<<endl;
		}
		if(p<=x||o>=x)break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


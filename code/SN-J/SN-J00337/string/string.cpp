#include<bits\stdc++.h>
using namespace std;
long long n;
long long cn=0,an=0,w[200005]={};
struct no{
	long long a;
	char c;
}s[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(long long i=1;i<=n;i++){
		cin >>s[i].a>>s[i].c;
		cn+=s[i].a;
		w[i]=cn;
	}
	//cout<<an<<" "<<cn<<" "<<w[n];
	long long m=0,lm=0,q=n;
	for(long long i=1;i<=n;i++){
		if(m*2>=cn)break;
		m+=s[i].a;
		if(m*2>=cn)m=cn/2;
		lm=cn-m+1;
		for(long long j=q;j>=1;j--){
			if(lm<=w[j]&&lm<=w[j-1]&&w[j-1]>(cn/2)){
				if(s[i].c!=s[j].c)an+=s[j].a;
				q--;
			}
			else if(lm<=w[j]&&lm<=w[j-1]&&w[j-1]<=(cn/2)){
				if(s[i].c!=s[j].c)an+=w[j]-ceil(cn/2);
				break;
			}
			else if(lm<=w[j]&&lm>w[j-1]){
				if(s[i].c!=s[j].c)an+=w[j]+1-lm;
				w[j]=lm-1;
				if(w[j]==w[j-1])q--;
				break;
			}
		}
	}
	cout<<an;
	return 0;
}

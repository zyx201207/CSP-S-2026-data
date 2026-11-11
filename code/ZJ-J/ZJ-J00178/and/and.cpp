#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],mmmmm;
struct node{
	int k[35],num=1;
	long long xx;
}s[200005]; 
bool cmp(node x,node y){
	if(x.num!=y.num)return x.num>y.num;
	else return x.xx>y.xx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mmmmm=max(mmmmm,a[i]);
		s[i].xx=a[i];
		while(a[i]!=0){
			s[i].k[s[i].num]=a[i]%2;
			a[i]/=2;
			s[i].num++;
		}
	}
	if(m==1){
		cout<<mmmmm<<endl;
		return 0;
	}
	sort(s+1,s+n+1,cmp);
	int p;
	for(p=1;;++p){
		if(s[p].num<s[m].num){
			break;
		}
	}
	bool px[p+2];
	memset(px,true,sizeof(px));
	for(int i=s[1].num;i>=1;--i){
		int num1=0;
		for(int j=1;j<=p;j++){
			if(px[j]&&s[j].k[i])num1++;
		}
		if(num1>=m){
			for(int j=1;j<=p;j++){
				if(!s[j].k[i])px[j]=0;
			}
		}
	}
	long long ansb[m+2],pg=1;
	for(int i=1;i<=p;i++){
		if(px[i])ansb[pg]=s[i].xx,pg++;
	}
	long ansc=ansb[1];
	for(int i=1;i<=m;++i)ansc&=ansb[i];
	cout<<ansc<<endl;
	int rp;
	rp++;
	return 0;
}

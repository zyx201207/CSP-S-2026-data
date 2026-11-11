#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],s[600000],cnt,vis[600000],q[600000];
long long bp[600000];
bool A;
int max(int a,int b){
	if(a>b) return a;
	return b;
}
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	A=true;
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1]){
			A=false;
		}
	}
	if(A&&n>6000){
		for(int i=1;i<=n;i++){
			q[a[i]]=max(q[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<q[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		cnt=0;
		memset(bp,0,sizeof(bp));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0||vis[a[j]]>cnt||s[vis[a[j]]]!=a[j]){
				s[++cnt]=a[j];
				vis[a[j]]=cnt;
			}else{
				cnt=vis[a[j]];
			}
		}
		for(int j=1;j<=cnt;j++){
		
					cout<<s[j];
				
			if(bp[s[j]]==0){
				
				q[s[j]]++;
				bp[s[j]]=1;
			}
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<q[i]<<" "; 
	}
	}
	
	return 0;
}

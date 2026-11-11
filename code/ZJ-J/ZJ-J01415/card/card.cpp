#include<bits/stdc++.h>
using namespace std;
int read(){
	int t=1,l=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return t*l;
}
const int MX=5e5+5;
int n,m;
int a[MX],ans[MX];
bool b[MX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		stack<int >st;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(st.top()!=a[j]){
					b[st.top()]=0;
					ans[st.top()]--;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				b[a[j]]=1;
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
int w[125255],k,aa[505][505],zhan[505][505],x,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	int asd=1;
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			zhan[i][j]=read();
			aa[j][i]=read();
			if(aa[j][i]>1&&aa[j-1][i]!=aa[j][i]) asd=0;
		}
	}
	while(q--){
		x=read(),y=read();
		if(asd==1){
			long long adssa=w[x]+w[y]+zhan[x][x];
			cout<<2*(y-x)*aa[1][1]+adssa;
		}
		long long ans=w[x]+w[y]+zhan[x][x];
		long long ansss=ans;
		for(int i=y;i>=x;i--){
			ansss=min(ansss,ans);
		}
		cout<<ansss<<endl;
	}
	return 0;
}

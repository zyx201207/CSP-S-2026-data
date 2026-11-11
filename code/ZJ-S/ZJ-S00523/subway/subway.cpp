#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,w[5005],t[20005][4],pc[20005][4];
int gl[10005],st[10005],s;
int b[10005];
long long mi;
void dfs(int x,int y,long long cnt){
	if(cnt>=mi) return;
	if(x==y){
		mi=min(cnt,mi);
		return;
	}
	for(int i=st[x];i<gl[x];i++){
		if(b[pc[i][2]]==0){
			b[pc[i][2]]=1;
			dfs(pc[i][2],y,cnt+pc[i][3]);
			b[pc[i][2]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int l,x,y=0,kx=m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>l>>x;
			if(j==1){
				t[y+1][1]=l;
				t[y+1][2]=kx+j;
				t[y+1][3]=x;
			}else{
				int jl=y+j*2-2;
				t[jl][1]=l;
				t[jl][2]=kx+j;
				t[jl][3]=x;
				t[jl+1][1]=kx+j-1;
				t[jl+1][2]=kx+j;
				t[jl+1][3]=0;
				gl[kx+j-1]++;
				gl[kx+j]++;
			}
			gl[kx+j]++;
			gl[l]++;
		}
		kx+=s;
		y+=s*2-1;
	}
	for(int i=1;i<=kx;i++){
		gl[i]+=gl[i-1];
	}
	for(int i=kx;i>=1;i--){
		st[i]=gl[i-1]+1;
		gl[i]=gl[i-1]+1;
	}
	for(int i=1;i<=y;i++){
		pc[gl[t[i][1]]][1]=t[i][1];
		pc[gl[t[i][1]]][2]=t[i][2];
		pc[gl[t[i][1]]][3]=t[i][3];
		pc[gl[t[i][2]]][1]=t[i][2];
		pc[gl[t[i][2]]][2]=t[i][1];
		pc[gl[t[i][2]]][3]=t[i][3];
		gl[t[i][1]]+=1;
		gl[t[i][2]]+=1;
	}
	while(q--){
		cin>>l>>x;
		mi=1e9;
		memset(b,0,sizeof(int));
		dfs(l,x,w[l]+w[x]);
		cout<<mi<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

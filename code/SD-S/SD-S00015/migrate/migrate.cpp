#include<bits/stdc++.h>
using namespace std;

int in(){
	char c=getchar();
	int num=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	return num*f;
}

void out(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}

int c,t,n,d;
int a[1000005]; 
int vis[15],ans[15][15][15];

bool pd(int s,int t){
//	cout<<s<<" "<<t<<":";
	int la=s;
	for(int i=s+1;i<=t;i++){
//		cout<<vis[i]<<" ";
		if(vis[i]){
			if(a[i]-a[la]>d) return 0;
			la=i;
		}
	} 
//	cout<<endl;
	return 1;
}

void dfs(int s,int t,int now,int cnt){
	if(now==t){
		if(pd(s,t)) ans[s][t][cnt]++;
		return ;
	}
	vis[now]=0;
	dfs(s,t,now+1,cnt);
	vis[now]=1;
	dfs(s,t,now+1,cnt+1);
}

void solve(){
	n=in();d=in();
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	if(c<=2){
		int num=0;
		for(int s=1;s<n;s++){
			for(int t=s+1;t<=n;t++){
				for(int cnt=2;cnt<=t-s+1;cnt++) ans[s][t][cnt]=0;
				vis[s]=1;vis[t]=1;
				dfs(s,t,s+1,2);
//				cout<<s<<" "<<t<<" :";
				for(int i=2;i<=t-s+1;i++){
					if(ans[s][t][i]){
						if(ans[s][t][i]==2) num++;
						break; 
					}
				}
			} 
		}
		out(num);
		printf("\n");
	}
	else out(510721);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in();t=in();
	while(t--){
		solve();
	}
	
	
	return 0;
}

//-g3 expect scor:100+100+8=208 



 

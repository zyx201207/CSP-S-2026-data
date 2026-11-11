#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c,d,q,x,y;

int read(){
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}	
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
struct qqq{
	int xian;
	int zh;
	int zhh;
	int t;
}k[100010];
void solve(){
	cin>>x>>y;
	int ans=0;
	if(c==9||c==10||c==11||c==7||c==8){
		ans+=a[x];
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i].zh;j++){
				if(k[j].zh==y){
					ans+=k[j].t;
					cout<<ans;
					return;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=0;i<m;i++){
		a[i]=read();								
	}
	for(int i=0;i<n;i++){	
		k[i].xian=i;
		k[i].zh=read();
		for(int j=0;j<k[i].zh;j++){
			k[j].zhh=read(),k[j].t=read();
		}							
	}
	while(q--){
		solve();
	}
	return 0;
}
